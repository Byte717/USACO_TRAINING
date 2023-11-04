#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int dp[101][3];

void add(int &a, int b){
    a += b;
    if(a >= MOD){
        a-= MOD;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int n, k, d; cin >> n >> k >> d;
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int i = 1; i <= n;i++){
        dp[i][0] = dp[i][1] = 0;
        for(int j = 1; j <= k;j++){
            if(i-j < 0){
                break;
            }
            if(j < d){
                add(dp[i][0], dp[i-j][0]);
                add(dp[i][1], dp[i-j][1]);
            }else{
                add(dp[i][1], dp[i-j][0]);
                add(dp[i][1], dp[i-j][1]);
            }
        }
    }
    cout << dp[n][1] << endl;
    return 0;
}