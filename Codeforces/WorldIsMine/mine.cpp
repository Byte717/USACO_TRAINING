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
    vector<int> a;
    int m;
    cin >> m;
    map<int, int> cnt;
    while (m--) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (auto const &[k, v]: cnt) {
        a.push_back(v);
    }
    int n = (int)a.size();
    vector<int> dp(n + 1, MOD);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        vector<int> ndp = dp;
        
        for (int k = 1; k <= n; k++) {
            int nv = dp[k - 1] + a[i - 1];
            
            if (nv <= i - k) {
                ndp[k] = min(ndp[k], nv);
            }
        }
        
        dp = ndp;
    }
    int ans = n;
    while (dp[ans] >= MOD) ans--;
    cout << n - ans << endl;
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