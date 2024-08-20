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
    ll n, m, c; cin >> n >> m >> c;
    vector<vector<ll>> adj(n);
    for(ll i = 0; i < m;i++){
        ll u,v; cin >> u >> v;
        adj[--v].push_back(--u);
        adj[u].push_back(v);
    }

    vector<ll> subtree(n, 0);
    auto findSize = [&](auto&& self, ll node, ll parent) -> void{
        subtree[node] = 1;
        for(auto &x : adj[node]){
            if(x != parent){
                self(self,x,node);
                subtree[node] += subtree[x];
            }
        }
    };
    findSize(findSize, 0,-1);
    ll ans = 1e18;
    auto dfs2 = [&](auto&& self, ll node, ll parent)->void{
        for(auto & x : adj[node]) if(x!=parent){
            ll inside = subtree[x], outside = n-subtree[x];
            ans = min(ans, inside*inside + outside*outside);
            self(self,x,node);
        }
    };
    dfs2(dfs2, 0,-1);
    cout << ans << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("prison.in","r",stdin);
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