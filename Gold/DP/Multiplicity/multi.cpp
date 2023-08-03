#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;


void slow(int n, vector<int> a){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i = 1; i <= n;i++){
        dp[i][1] = 1;
        for(int j = 2; j <= n;j++){
            if(a[i-1] % j == 0){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }else{
                dp[i][j] = dp[i-1][j];
            }
            dp[i][j] %= MOD;
        }
    }
    cout <<  dp[n][n] << endl;
}

void faster(int n, vector<int> a){
    vector<ll> dp(n+5, 0);
    dp[0] = 1;
    for(int i = 1; i <= n;i++){
        vector<int> curr;
        for(int j = 1; j * j <= a[i-1];j++){
            if(a[i-1] %j == 0){
                curr.push_back(j);
                if(j != a[j]/j){
                    curr.push_back(a[i]/j);
                }
            }
        }
        sort(all(curr));
        reverse(all(curr));
        for(int &i : curr){
            dp[i] += dp[i-1];
            dp[i] %= MOD;
        }
    }
    int ans = 0;
    for(int i = 0; i <=n ;i++){
        ans += dp[i];
    }
    ans %= MOD;
    cout << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("multi.in","r",stdin);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    faster(n,a);
    return 0;
}