#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int a, b; cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int>(b+1,INF));
    if(a == b){cout << 0 << endl; return 0;}
    for(int i = 0; i <= a;i++){
        for(int j = 0; j <= b;j++){
            if(i == j){
                dp[i][j] = 0;
            }else{
                dp[i][j] = INF;
                for(int k = 1; k < i;k++){
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j]+1);
                }
                for(int k = 1; k < j;k++){
                    dp[i][j] = min(dp[i][j],dp[i][k] + dp[i][j-k] +1);
                }


            }
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}