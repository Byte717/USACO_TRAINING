#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;
const int MAXN = 1e5+5;

/*
use dp idk what else:

What I learned Boredom: Revisit *****
    - dp can be used to find optimal solution and count the number of solutions.

*/


vector<ll> a(MAXN,0), f(MAXN,0);

// Life_Is_A_Game
int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("boredom.in","r",stdin);
    int n; cin >> n;

    for(int i = 0; i < n;i++){
        int x; cin >> x;
        a[x]++;
    }
    f[1] = a[1];
    for(int i = 2; i < MAXN;i++){
        f[i] = max(f[i-1], f[i-2] + a[i] * i);
    }
    cout << f[MAXN- 1] << endl;
    // vector<pair<int,int>> dp(1e5+5);
    // dp[0].first = cnt[0];
    // dp[1].first = cnt[1];
    // for(int i = 2; i < (int)1e5+5;i++){
    //     dp[i].first = max(dp[i-2].first, dp[i-1].second) + cnt[i]*i;
    //     dp[i].second = max(dp[i-1].first, dp[i-1].second);
    // }
    // cout << max(dp[n-1].first, dp[n-1].second) << endl;
    return 0;
}