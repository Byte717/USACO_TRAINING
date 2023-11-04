#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

// #define debug

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e8;

/*

What I learned Caesar's legions: *** REVISIT *****
    - dp can be used to count states
    - add another dimention to dp when another state is needed
        - like, num footmen, num horseman, and current type


*/


int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef debug
        freopen("legions.in","r",stdin);
    #endif
    int n1, n2, k1, k2; cin >> n1 >> n2 >> k1 >> k2;
    vector<vector<vector<int>>> dp(n1+5, vector<vector<int>>(n2+5,vector<int>(2,0)));
    dp[0][0][0] = dp[0][0][1] = 1;
    for(int i = 0; i <= n1;i++){
        for(int j = 0; j <= n2;j++){
            if(i == 0 && j == 0) continue;

            for(int l = 1; l <= k1;l++){
                if(i - l >= 0){
                    dp[i][j][0] += dp[i-l][j][1];
                    dp[i][j][0] %= MOD;
                }else{
                    break;
                }
            }

            for(int l = 1; l <= k2;l++){
                if(j - l >= 0){
                    dp[i][j][1] += dp[i][j-l][0];
                    dp[i][j][1] %= MOD;
                }else{
                    break;
                }
            }
        }
    }
    cout << (dp[n1][n2][0] + dp[n1][n2][1]) % MOD << endl;
    return 0;
}