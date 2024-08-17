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
    string s[2];
    cin >> s[0] >> s[1];
    int ans = 0;
    for (int i = 1; i + 1 < n; i++) {
        for (int j = 0; j <= 1; j++) {
            if (s[j][i] == '.' && s[j][i + 1] == '.' && s[j][i - 1] == '.' && s[j ^ 1][i] == '.' && s[j ^ 1][i - 1] == 'x' && s[j ^ 1][i + 1] == 'x') {
                ans++;
            }
        }
    }
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