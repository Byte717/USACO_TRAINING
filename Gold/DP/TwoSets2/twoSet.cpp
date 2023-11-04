#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;
    int target = n*(n+1)/2; 
    if(target % 2 == 0){
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int>> dp(n,vector<int>((target/2)+1, 0));
    dp[0][0] = 1;
    for(int i = 1; i < n;i++){
        for(int j = 0; j <= target){
            dp[i][j] = dp[i-1][j];
            if(j-i >= 0){
                dp[i][j] += dp[i-1][j-i];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n-1][target/2] << endl;
    return 0;
}