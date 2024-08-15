#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define debug

#ifndef debug
    #pragma GCC optimize("O3","unroll-loops")
    #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#endif

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

void solve(){
    ll n, x; cin >> n >> x;
    vector<ll> a(n+1);
    for(int i = 1; i <= n;i++){cin >> a[i];}
    for(int i = 1; i <= n;i++){
        a[i] += a[i-1];
    }
    // partial_sum(a.begin() + 1, a.end(), a.begin() + 1);
    vector<int> dp(n+2);
    ll ans = 0;
    for(int i = n-1; i >= 0;i--){
        int q = upper_bound(all(a), a[i]+x) - a.begin();
        dp[i] = dp[q] + q-i-1;
        ans += dp[i];
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("games.in","r",stdin);
    #ifdef LOCAL
	auto _clock_start = chrono::high_resolution_clock::now();
    #endif 
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    #ifdef LOCAL
    cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
        chrono::high_resolution_clock::now()
            - _clock_start).count() << "ms." << endl;
    #endif
    return 0;
}