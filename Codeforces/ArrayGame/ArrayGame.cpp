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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (k >= 3) {
        cout << 0 << endl;
        return;
    }
    sort(begin(a), end(a));
    int d = a[0];
    for (int i = 0; i < n - 1; i++) d = min(d, a[i + 1] - a[i]);
    if (k == 1) {
        cout << d << endl;
        return;
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < i; j++) {
        int v = a[i] - a[j];
        int p = lower_bound(begin(a), end(a), v) - begin(a);
        if (p < n) d = min(d, a[p] - v);
        if (p > 0) d = min(d, v - a[p - 1]);
    }
    cout << d << endl;
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