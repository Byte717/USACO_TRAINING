#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int dx[] = {1, 0, -1, 0, 3, 0, -3, 0, 2, 2, 1, 1, -1, -1, -2, -2};
int dy[] = {0, 1, 0, -1, 0, 3, 0, -3, 1, -1, 2, -2, 2, -2, 1, -1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n, t; cin >> n >> t;
    vector<vector<int>> field(n,vector<int>(n));
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++) cin >> field[i][k];
    }
    vector<vector<int>> dist(n,vector<int>(n,INT32_MAX));
    vector<vector<bool>> visited(n,vector<bool>(n));
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({0,{0,0}});
    dist[0][0] = 0;
    while(!pq.empty()){
        int d, x, y; 
        tie(d,x,y) = pq.top();
        pq.pop();
        if(visited[x][y]){continue;}
        visited[x][y] = true;
        for(int i = 0; i < 16;i++){
            int newX = x + dX[i], newY = y + dY[i];

            if(newX < 0 || newX >= n || newY < 0 || newY >= n){continue;}
            if(dist[newX][newY] > dist[x][y] + 3 * t + field[newX][newY]){
                dist[newX][newY] = dist[x][y] + 3 * t + field[newX][newY];
                pq.push({-dist[newX][newY], {newX,newY}});
            }
        }
        int manhattan = n - x - 1 + n - y - 1;
        if(manhattan < 3){
            dist[n-1][n-1] = min(dist[n-1][n-1], dist[x][y] + manhattan *t);
        }
    }
    cout << dist[n-1][n-1] << endl;
    return 0;
}