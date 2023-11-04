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
    int sum = 0;
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
        sum += x[i];
    }
    vector<vector<int>> dp(n, vector<int>(n));
    for(int l = n-1; l >= 0; l--){
        for(int r = l; r < n; r++){
            if(l == r){
                dp[l][r] = x[i];
            }else{
                dp[l][r] = max(x[l]-dp[l+1][r],x[r]-dp[l][r-1]);
            }
        }
    }
    cout << (sum+dp[0][n-1])/2 << endl;
    return 0;
}