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

#define MAXW 200200
#define MAXNM 200200

ll n, m, k, w, p;
ll arr[MAXW], prr[MAXNM];


static inline ll calcc(ll i, ll j) {
    ll upr = min(i, n - k);
    ll leftr = min(j, m - k);
    ll upl = max(-1LL, i - k);
    ll leftl = max(-1LL, j - k);
    return (upr - upl) * (leftr - leftl);
}
 
void solve(){
    cin >> n >> m >> k >> w;
    for (ll i = 0; i < w; ++i)
        cin >> arr[i];
    sort(arr, arr + w);
    reverse(arr, arr + w);
    p = 0;
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < m; ++j)
            prr[p++] = calcc(i, j);
    sort(prr, prr + p);
    reverse(prr, prr + p);
    ll sum = 0;
    for (ll i = 0; i < w; ++i)
        sum += prr[i] * arr[i];
    cout << sum << endl;

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