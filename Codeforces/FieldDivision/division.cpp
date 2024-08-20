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

bool cmp(pair<int, int> &a, pair<int, int> &b){
    if(a.x != b.x) return a.x > b.x;
    return a.y < b.y;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> a(k);
    map<pair<int, int>, int> idx;
    for(int i = 0; i < k; ++i){
        cin >> a[i].x >> a[i].y;
        idx[a[i]] = i;
    }
    sort(all(a), cmp);
    vector<int> ans(k);
    int total = 0;
    int cur = m + 1;
    int last = n;
    for(auto e: a){
        if(cur > e.y) {
            ans[idx[e]] = 1;
            total += (cur - 1) * (last - e.x);
            cur = e.y;
            last = e.x;
        }
    }
    total += (cur - 1) * last;
    cout << total << "\n";
    for(int e: ans) cout << e << " ";
}
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