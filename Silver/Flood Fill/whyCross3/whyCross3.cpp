#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;


vector<vector<bool> vis;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("whyCross3.in","r",stdin);
    int n, k r; cin >> n >> k >> r;
    vis = vector<vector<bool>>(n,vector<bool>(n,false));
    set<pair<int,int>> roads;
    for(int i = 0; i < r;i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        roads.insert({--a,--b});
        roads.insert({--c,--d});
    }
    vector<pair<int,int>> cows(k);
    for(int i = 0; i < k;i++){
        cin >> cows[i].first >> cows[i].second;
        cows[i].first--; cows[i].second--;
    }
    const int dX[4] = {0,1,0,-1};
    const int dY[4] = {1,0,-1,0};
    auto floodFill = [&](int x, int y, bool start){
        if(x < 0 || x >= n || y >=n || y < 0) return;
        
        if(vis[x][y]) return;
        if(!start && roads.find({x,y}) != roads.end()){
            return;
        }
        vis[x][y] = true;
        for(int i = 0; i < 4;i++){
            floodFill(x+dX[i],y+dY[i],false);
        }

    };

    int ans = 0;
    for(int i = 0; i < k-1;i++){
        for(int j = i+1; j < k;j++){
            vis = vector<vector<bool>>(n,vector<bool>(n,false));
            floodFill(cows[i].first,cows[i].second,true);
            if(vis[cows[i].first][cows[i].second] && vis[cows[j].first][cows[j].second]){
                ans++;
            }

        }
    }
    cout << ans << endl;
}
