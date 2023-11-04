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


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("where.in","r",stdin);
    int n; cin >> n;
    vector<vector<char>> grid(n,vector<char>(n));
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            cin >> grid[i][j];
        }
    }
    unordered_set<char> colors;
    vector<vector<bool>> visited(n,vector<bool>(n,false)), isPCL(n,vector<bool>(n,false));
    int lowX, lowY, highX, highY;

    function<void(int,int)> floodfill = [&](int x, int y){
        if(x < lowX || x > highX || y < lowY || y > highY){return;}
        if(visited[x][y]){return;}
        visited[x][y] = true;
        colors.insert(grid[x][y]);
        for(int i = 0; i < 4;i++){
            floodfill(x+dirX[i], y+dirY[i]);
        }
    };

    auto works = [&](int x1, int y1, int x2, int y2){
        for(int i = 0; i < n;i++){
            for(int j = 0;j < n;j++){
                visited[i][j] = false;
            }
        }

        lowX = x1; lowY = y1; highX = x2; highY = y2;
        floodfill(x1,y1);
        if(colors.size() == 2){
            int numBlocks = 0, totalBlocks = 0;
            for(int i = x1; i <= x2;i++){
                for(int j = y1;j <= y2;j++){
                    if(isPCL[i][j]){
                        numBlocks++;
                    }
                    totalBlocks++;
                }
            }
            if(totalBlocks == numBlocks) return false;

            for(int i = x1; i < x2;i++){
                for(int j = y1;j < y2;j++){
                    isPCL[i][j] = true;
                }
            }
            return true;
        }
        return false;
    };

    int ans = 0;
    for(int i1 = 0; i1 < n-1;i1++){
        for(int j1 = 0; j1 < n-1;j1++){

            for(int i2 = i1+1; i2 < n;i2++){
                for(int j2 = j1+1;j2 < n;j2++){
                    if(works(i1,j1, i2,j2)){
                        ans++;
                        colors.clear();
                    } 
                }
            }

        }
    }
    freopen("where.out","w",stdout);
    cout << ans << endl;
    return 0;
}
