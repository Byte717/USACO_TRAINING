#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define debug

#ifndef debug
    #pragma GCC optimize("O3","unroll-loops")
    #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#endif

typedef unsigned long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;
/* Quick hints:
[]  Capture nothing (or, a scorched earth strategy?)
[&] Capture any referenced variable by reference
[=] Capture any referenced variable by making a copy
[=, &foo]   Capture any referenced variable by making a copy, but capture variable foo by reference
[bar]   Capture bar by making a copy; don't copy anything else
[this]  Capture the this pointer of the enclosing class
*/

const auto LOG2 = [](int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
};

template<typename T> inline bool flipped(T a,int i){return a&(1ll<<i);}
template<typename T> inline T pow2(int exp){return (1ll << exp);}

void solve(){
    ll n,k; cin >> n >> k; 

    auto val = [&](ll x)->pair<ll, ll>{
        ll val1 = (x+k-1+k)*x/2;
        ll val2 = (k+n-1+k)*n/2 - val1;
        return {val1,val2};
    };
    ll lo = 1, hi = n;
    ll cur = 1;
    while (lo <= hi){
        ll mid = (lo + hi)/2;
        auto [a,b] = val(mid);
        if(b > a){
            cur = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    auto [a1,b1] = val(cur);
    auto [a2,b2] = val(cur+1);
    cout << min(b1-a1, a2-b2) << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
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