#include <bits/stdc++.h>
#define ll long long

using namespace std; 
const int MAXN = 1e4;

int dp[MAXN][MAXN], grid[MAXN][MAXN];
int n;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("paths.in","r",stdin);
    int n; cin >> n;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            char x; cin >> x;
            if(x == '*') grid[i][j] = 1;
            else grid[i][j] = 0;

            if(i == 0 || j == 0){
                dp[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            if(i > 0 && j > 0){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            if(grid[i][j] == 1){
                dp[i][j] = 0;
            }
        }
    }
    cout << dp[n-1][n-1] << endl;
    return 0;
}