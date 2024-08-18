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

const ll INF = 1e9;
const ll MOD = 1e9+7;


int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        g[p - 1].push_back(i);
    }
    
    auto check = [&](auto&& self, int v, int x) -> bool {
      if (x > INF) return false;
      bool isLeaf = true;
      if (v) x += max(0, x - a[v]);
      for (auto u : g[v]) {
        isLeaf = false;
        if (!self(self, u, x)) return false;
      }
      return (!isLeaf || x <= a[v]);
    };
    
    int l = 1, r = INF;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(check, 0, mid)) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    
    cout << a[0] + l - 1 << '\n';
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