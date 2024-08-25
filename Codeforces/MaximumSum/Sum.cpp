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


ll LOG2(ll n){
    ll ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

template<typename T> inline bool flipped(T a,ll i){return a&(1ll<<i);}
template<typename T> inline T pow2(ll exp){return (1ll << exp);}

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for(auto &x : a){
        cin >> x;
    }
    ll S = 0, sum = 0;
    ll cur = 0;
    for(ll i = 0; i < n;i++){
        sum += a[i];
        cur += a[i];
        cur = max(cur, 0ll);
        S = max(S, cur);
    }
    sum = (sum % MOD + MOD) % MOD;
    S %= MOD;
    ll pow2 = 1;
    for(ll i = 1; i < k;i++){
        pow2 *= 2;
        pow2 %= MOD;
    }
    cout << (sum + S*pow2 - S + MOD) % MOD << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    #ifdef LOCAL
	auto _clock_start = chrono::high_resolution_clock::now();
    #endif 
    ll t = 1; cin >> t;
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