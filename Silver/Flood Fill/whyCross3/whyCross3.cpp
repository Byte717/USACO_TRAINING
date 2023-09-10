#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>

using namespace std;


vector<vector<bool>> vis;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("countcross.in","r",stdin);
    int n, k, r; cin >> n >> k >> r;
    vis = vector<vector<bool>>(n,vector<bool>(n,false));
    vector<vector<set<pair<int,int>>>> roads(n, vector<set<pair<int,int>>>(n));
    for(int i = 0; i < r;i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        roads[--a][--b].insert({--c,--d});
        roads[c][d].insert({a,b});
    }
    vector<pair<int,int>> cows(k);
    for(int i = 0; i < k;i++){
        cin >> cows[i].first >> cows[i].second;
        cows[i].first--; cows[i].second--;
    }
    const int dX[4] = {0,1,0,-1};
    const int dY[4] = {1,0,-1,0};
    std::function<void(int,int)> floodFill = [&](int x, int y){
        if(x < 0 || x >= n || y >= n || y < 0) return;
        
        if(vis[x][y]) return;
        vis[x][y] = true;
        for(int i = 0; i < 4;i++){
            int newX = x + dX[i], newY = y + dY[i];
            if(roads[x][y].count({newX,newY}) == 0){
                floodFill(newX,newY);
            }
        }

    };
    // floodFill(1,1,true);
    int ans = 0;
    for(int i = 0; i < k-1;i++){
        vis = vector<vector<bool>>(n,vector<bool>(n,false));
        floodFill(cows[i].first,cows[i].second);
        for(int j = i+1; j < k;j++){
            if(!vis[cows[j].first][cows[j].second]){
                ans++;
            }
        }
    }
    freopen("countcross.out","w",stdout);
    cout << ans << endl;
}
