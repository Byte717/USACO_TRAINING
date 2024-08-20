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
/*
for all indices i such that a[i] < a[i-1], you can binary search on the minimum operations done to it, as it increases by powers of 2
*/
void solve(){
    int n;
    vector<ll> v;
    cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	for (int i = 1; i < n; i++) {
		if (v[i - 1] > 1 && v[i] == 1) {
			cout << "-1\n";
			return;
		}
	}
	vector<ll> ops(n, 0);
	for (int i = 1; i < n; i++) {
		ll him = v[i - 1];
		ll me = v[i];
		ll extra = 0;
		while (him != 1 && him * him <= me)
			extra -= 1, him *= him;
		while (me < him)
			extra++, me *= me;
		ops[i] = max(0ll, ops[i - 1] + extra);
	}
	ll ans = 0;
	for (auto i : ops)
		ans += i;
	cout << ans << "\n";        
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