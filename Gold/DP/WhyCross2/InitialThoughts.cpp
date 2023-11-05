#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("nocross.in","r",stdin);
    int n; cin >> n;
    vector<int> left(n), right(n);
    for(int i = 0; i < n;i++){
        cin >> left[i];
    }

    for(int i = 0; i < n;i++){
        cin >> right[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <=n;j++){
            if(abs(left[i-1]-right[j-1]) <= 4){
                dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]) + 1);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= n;i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}