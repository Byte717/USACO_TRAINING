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

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto & x : a) cin >> x;
    vector<int> pos(n);
    vector<pair<int,int>> ans;
    iota(all(pos), 0);
    for(int operation = n-1; operation;operation--){
        vector<int> occ(operation,-1); // last occurence of some val mod operation
        for(auto j : pos){
            if(occ[a[j] % operation] != -1){
                ans.emplace_back(j, occ[a[j] % operation]);
                pos.erase(find(all(pos), j));
                break;
            }
            occ[a[j] % operation] = j;
        }
    }
    reverse(all(ans));
    cout << "YES\n";
    for (auto [x, y] : ans) cout << x + 1 << ' ' << y + 1 << '\n';
}

int main(){
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