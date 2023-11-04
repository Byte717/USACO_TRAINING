#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n,B; cin >> n >> B;
    vector<int> f(n);
    for(int i = 0; i < n;i++){
        cin >> f[i];
    }
    vector<int> s(B), d(B);
    for(int i = 0; i < B;i++){
        cin >> s[i] >> d[i];
    }
    int ans = -1;
    bool exit = false;
    vector<vector<bool>> dp(B, vector<int>(n));
    for(int b = 0; b < B;b++){
        if(exit) break;
        for(int i = 0; i < n;i++){
            if(f[i] > s[b]){
                dp[i][b] = false;
                continue;
            }
            if(i == 0 && b == 0){
                dp[i][b] = true;
            }
            for(int k = 0; k < i;k++){
                if(dp[k][b] && k + d[b] >= i){
                    dp[i][b] = true;
                }
            }

            for(int k = 0; k < b;k++){
                if(dp[i][k]){
                    dp[i][b] = true;
                }
            }
            if(i == n-1 && dp[i][b]) {
                ans = b;
                exit = true;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}