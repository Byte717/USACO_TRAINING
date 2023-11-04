#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

const int dX[4] = {-1, 0, 1, 0};
const int dY[4] = {0, 1, 0, -1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;
    vector<int> left(n+1), right(n+1);
    for(int i = 1; i <= n;i++){
        cin >> left[i];
    }
    for(int i = 1; i <= n;i++){
        cin >> right[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <=n;j++){
            if(abs(left[i]-right[j]) <= 4){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1]));
            }
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}