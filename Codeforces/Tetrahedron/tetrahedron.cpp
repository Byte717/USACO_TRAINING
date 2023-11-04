#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;
/*
what I learned tetrahedron:
    - DP: if memory is a problem, just keep the parts you need, dp[i-1]. then on the i'th iteration, calculate dp[i] and set dp[i-1] to dp[i] and repeat

*/


void normalDp(ll n){
    vector<vector<ll>> dp(n+1,vector<ll>(4,0));
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    for(ll i = 2; i <= n;i++){
        for(ll j = 0; j < 4;j++){ // current point
            for(ll adj = 0; adj < 4;adj++){ // point adj from 
                if(j != adj){
                    dp[i][j] += dp[i-1][adj];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    cout << dp[n][0] << endl;
}

void fastDp(ll n){
    ll numZ = 1;
    ll numABC = 0;
    for(int i = 1; i <= n;i++){
        ll newZ = (numABC * 3LL) % MOD;
        ll newABC = (newABC * 2LL + numZ) % MOD;
        numZ = newZ;
        numABC = newABC;
    }
    cout << numZ << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("tetrahedron.in","r",stdin);
    ll n; cin >> n;
    fastDp(n);
    return 0;
}