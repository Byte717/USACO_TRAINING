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

template<typename T> inline bool flipped(T a,int i){return a&(1ll<<i);}
template<typename T> inline T pow2(int exp){return (1ll << exp);}

void solve(){
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(all(a));
    int ans = max((a[0]-0), 2*(x-a[n-1]));
    for(int i = 1; i < n;i++){
        ans = max(ans, a[i]-a[i-1]);
    }
    cout << ans << endl;
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