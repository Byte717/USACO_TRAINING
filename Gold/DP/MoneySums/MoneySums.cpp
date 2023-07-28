#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

int n;
vector<int> money;
int MX = -1;
void solve(){
    vector<vector<bool>> dp(n+1,vector<bool>(MX+1,false));
    // for(int i = 0; i < n;i++){
    //     dp[i][money[i]] = true;
    // }
    dp[0][0] = true;
    for(int i = 1; i <= n;i++){
        for(int j = 0; j <= MX;j++){
            dp[i][j] = dp[i-1][j];
            if(j-money[i-1] >= 0 && dp[i-1][j-money[i-1]]){
                dp[i][j] = true;
            }
        }
    }
    vector<int> ans;
    for(int j = 1; j <= MX; j++){
        if(dp[n][j]) ans.push_back(j);
    }
    cout << ans.size() << endl;
    for(int &i : ans) cout << i << ' ';
    cout << endl;
}



int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("MoneySums.in","r",stdin);
    cin >> n;
    money = vector<int>(n);
    for(int i = 0; i < n; i++){
        cin >> money[i];
        MX += money[i];
    }
    solve();
    return 0;
}