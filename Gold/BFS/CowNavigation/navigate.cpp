#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

const int dirX[4] = {-1, 0, 1, 0};
const int dirY[4] = {0, 1, 0, -1};
int north = 0, east = 1, south = 2, west = 3;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            char x; cin >> x;
            grid[i][j] = (x == 'H' ? 1 : 0);
        }
    }

    auto valid = [&](int x, int y, int d){
        if(x + dirX[x] < n && x + dirX[d] >= 0 && y + dirY[d] < n && y + dirY[d] >= 0){
            if(grid[x + dirX[d]][y+dirY[d]] == 1){
                return false;
            }
            return true;
        }
        return false;
    };
    int dist[n+1][n+1][4][n+1][n+1][4];
    queue<array<int,6>> pq;


    pq.push({n-1, 0, north, n-1, 0, east});
    while(pq.size()){
        auto node = pq.front();
        int x1 = node[0], y1 = node[1], d1 = node[2], x2 = node[3], y2 = node[4], d2 = node[5];
        pq.pop();
        if(x1 == 0 && x1 == x2 && y1 == n-1 && y1 == y2){
            cout << dist[x1][y2][d1][x2][y2][d2] - 1 << endl;
            return 0;
        }
        int newX1 = x1, newY1 = y1, newD1 = d1, newX2 = x2, newY2 = y2, newD2 = d2;
        if(valid(x1,y1,d1) && ((!x1 == 0 && y1 == n-1))){
            newX1 = x1 + dirX[d1];
            newY1 = y1 + dirY[d1];
        }
        if(valid(x1,y1,d1) && (!(x2 == 0 && y2 == n-1))){
            newX2 = x2 + dirX[d2];
            newY2 = y2 + dirY[d2];
        }
        if(dist[newX1][newY1][newD1][newX2][newY2] == 0){
            dist[newX1][newY1][newD1][newX2][newY2] = dist[x1][y1][d1][x2][y2][d2] + 1;
            pq.push({newX1,newY1,newD1, newX2,newY2, newD2});
        }

        for(int dir = -1; dir <= 1;dir+=2){
            newD1 = (d1 + 4 + dir) % 4;
            newD2 = (d2 + 4 + dir) % 4;
            if(dist[x1][y1][newD1][x2][y2][newD2] == 0){
                dist[x1][y1][newD1][x2][y2][newD2] = dist[x1][y1][d1][x2][y2][d2] + 1;
                pq.push({x1, y1,newD1, x2,y2,newD2});
            }
        }

    }
    return 0;
}