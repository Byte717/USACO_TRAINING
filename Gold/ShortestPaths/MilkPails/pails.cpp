#include <bits/stdc++.h>
#define ll long long
#define INF 1e10

using namespace std; 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("pails.in","r",stdin);
    int x, y, k, m; cin >> x >> y >> k >> m;
    int dist[x+1][y+1];
    for(int i = 0; i < x;i++){
        for(int j = 0; j < y;j++){
            dist[i][j] = INF;
        }
    }

    queue<pair<int,int>> q;
    q.push({0,0});
    dist[0][0] = 0;
    while(!q.empty()){
        auto top = q.front(); q.pop();
        int newDist = dist[top.first][top.second]+1;
        
        
    }
    return 0;
}