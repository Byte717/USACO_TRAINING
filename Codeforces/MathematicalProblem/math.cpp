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
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto cost = [&](vector<int> s) {
      if (ranges::count(s, 0)) return 0;
      int res = 0;
      for (int c : s)
        if (c > 1) res += c;
      return max(res, 1);
    };
    int ans = 1e6;
    for(int i = 0; i+1 < n;i++){
        vector<int> v;
        for(int j = 0; j < n;j++){
            if(j == i){
                v.push_back(stoi(s.substr(i,2)));
            }else if(j != i+1){
                v.push_back(stoi(s.substr(j,1)));
            }
        }
        ans = min(ans, cost(v));
    }
    cout << ans << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
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