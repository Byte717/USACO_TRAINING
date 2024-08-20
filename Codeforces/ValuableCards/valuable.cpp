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

const int A = 1e6 + 1;
bool used[A];
bool divs[A];

void solve(){
    int n, x;
	cin >> n >> x;
	vector<int> a(n);
	vector<int> vecDivs;
	for (int d = 1; d * d <= x; d++) {
		if (x % d == 0) {
			divs[d] = true;
			vecDivs.push_back(d);
			if (d * d < x) {
			    vecDivs.push_back(x / d);
				divs[x / d] = true;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cin >> a[i];
    	int ans = 1;
	used[1] = true;
	vector<int> cur{ 1 };
	for (int i = 0; i < n; i++) {
		if (!divs[a[i]])
			continue;
		vector<int> ncur;
		bool ok = true;
		for (int d : cur)// go through running divisors
			if (1ll * d * a[i] <= x && divs[d * a[i]] && !used[d * a[i]]) { // if the product doesn't exceed x and d*ai is a divisor and its not used
				ncur.push_back(d * a[i]);
				used[d * a[i]] = true;
				if (d * a[i] == x)
					ok = false;
			}
		for (int d : ncur)
			cur.push_back(d);
		if (!ok) { // we found a number that completes the subset of factors
			ans++; // new segment and mark what is pending as unused
			for (int d : cur)
				used[d] = false;
			used[1] = true;
			used[a[i]] = true;
			cur = vector<int>{ 1, a[i] }; // new running used factors
		}
	}
	for (int d : vecDivs) {
	    divs[d] = false;
	    used[d] = false;
	}
	cout << ans << '\n';
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