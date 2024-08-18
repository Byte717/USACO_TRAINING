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


const int N = 2e5 + 5;
int n, k, d[2*N];
void solve(){
    cin >> n >> k;
    fill(d, d+2*k, 0);
    int mx = -1;
    for(int i = 0; i < n;i++){
        int x; cin >> x;
        d[x%(2*k)]++;
        mx = max(mx, x);
    }
    int cnt = 0;
    int ans = INT_MAX;
    for (int i = 0; i <= k - 2; i++) {
        cnt += d[i];
    }
    for (int l = 0, r = k-1; l < 2*k; l++, r++) {
        if (r >= 2*k) r -= 2*k;
        if (cnt += d[r]; cnt == n) {
            int wait = (r-mx) % (2*k);
            if (wait < 0) wait += 2*k;
            ans = min(ans, mx + wait);
        }
        cnt -= d[l];
    }

    if (ans == INT_MAX) {
        ans = -1;
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