#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}
int n, m; 
vector<vector<char>> grid, last;
vector<vector<int>> dist;
pair<int,int> start, end;
vector<vector<bool>> visited;

void floodfill(int i,int j){
    queue<pair<int,int>> q;
    q.push({i,j});

    while(!q.empty()){
        auto &[x,y] = q.front();
        q.pop();
        for(int i = 0; i < 4;i++){
            int newX = x + dirX[i], newY = y + dirY[i];
            if(dist[x][y] + 1 < dist[newX][newY]){
                dist[newX][newY] = dist[x][y] + 1;
                switch(i){
                    case 0:
                        last[newX][newY] = 'R';
                        break;
                    case 1:
                        last[newX][newY] = 'D';
                        break;
                    case 2:
                        last[newX][newY] = 'L';
                        break;
                    case 3:
                        last[newX][newY] = 'U';
                        break;
                }
            }
        }
    }
}



int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    cin >> n >> m;
    grid = vector<vector<char>>(n,vector<int>(m));
    last = vector<vector<char>>(n,vector<int>(m,'0'));
    visited = vector<vector<bool>(n,vector<int>(m,false));
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                start.first = i;
                start.second = j;
            }else if(grid[i][j] == 'B'){
                end.first = i;
                end.second = j;
            }
        }
    }


    return 0;
}