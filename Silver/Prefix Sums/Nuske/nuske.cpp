#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define MAXN 2001
typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};


char grid[MAXN][MAXN]; int prefix1[MAXN][MAXN], prefix2[MAXN][MAXN], prefix3[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n,m,q; cin >> n >> m >> q;
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= m;j++){
            cin >> grid[i][j];
            prefix1[i][j] = (grid[i][j] == '1')+prefix1[i-1][j] + prefix1[i][j-1] - prefix1[i-1][j-1];
            prefix2[i][j] = (grid[i-1][j] == '1' && grid[i][j] == '1')+prefix2[i][j-1] + prefix2[i-1][j] - prefix2[i-1][j-1];
            prefix3[i][j] = (grid[i][j-1] == '1' && grid[i][j] == '1')+prefix3[i][j-1] + prefix3[j-1][i] - prefix3[i-1][j-1];
        }
    }
    for(int i = 0; i < q;i++){
        int x1, y1, x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        int totalBlue = prefix1[x2][y2] - prefix1[x1-1][y2] - prefix1[x2][y1-1] + prefix1[x1-1][y1-1];
        int horizontalEdges = prefix2[x2][y2] - prefix2[x1-1][y2] - prefix2[x2][y1-1] + prefix2[x1-1][y1-1];
        int verticalEdges = prefix3[x2][y2] - prefix3[x1-1][y2] - prefix3[x2][y1-1] + prefix2[x1-1][y1-1];
        cout << totalBlue-horizontalEdges-verticalEdges << endl;
    }
    return 0;
}