#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}
/*
dp[i][j] = max profit from i sequences if the last element has index j in it.



*/
int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("job.in","r",stdin);
    int n, m, k; cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    vector<ll> pref(n+1,0);
    for(int i = 0; i < n; i++){
        pref[i+1] = pref[i] + a[i];
    }
    vector<vector<ll>> dp(k+1,vector<ll>(n+1,0));
    for(int i = 1; i <= k;i++){
        for(int j  = 1; j <= n;j++){
            if(i * m > j){
                continue;
            }else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j-m] + pref[j] - pref[j-m]);
            }
        }
    }
    cout << dp[k][n] << endl;
    return 0;
}