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

// vector<bool> vis;
// vector<vector<ll>> adj;
// vector<ll> subtree, first, last;
// ll n, m;
// ll ans, cnt;

// void dfs(ll node, ll parent){
//     first[node] = last[node] = ++cnt;
//     subtree[node] = 1;
//     vis[node] = true;
//     for(auto &x : adj[node]){
//         if(x == parent) continue;
//         if (!vis[x]){
//             dfs(x, node);
//             subtree[node] += subtree[x];
//         }
//         last[node] = min(last[node], last[x]);
//     }
//     if(first[node] == last[node]){ // this is a tree!
//         ans = max(ans, subtree[node]*(n-subtree[node]));
//     }
// }

// void solve(){
//     cin >> n >> m;
//     vis.resize(n);
//     adj = vector<vector<ll>>(n);
//     fill(all(vis), false);
//     first = vector<ll>(n);
//     last = vector<ll>(n);
//     ans = 0;cnt = 0;
//     for(ll i = 0; i < m;i++){
//         ll a,b; cin >> a >> b;
//         adj[--a].push_back(--b);
//         adj[b].push_back(a);
//     }
//     dfs(0,-1);
//     cout << n*(n-1)/2-ans << endl;
// }

// int main(){
//     cin.tie(0)->sync_with_stdio(0);
//     // freopen("","r",stdin);
//     #ifdef LOCAL
// 	auto _clock_start = chrono::high_resolution_clock::now();
//     #endif 
//     ll t = 1; cin >> t;
//     while(t--){
//         solve();
//     }
//     #ifdef LOCAL
//     cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
//         chrono::high_resolution_clock::now()
//             - _clock_start).count() << "ms." << endl;
//     #endif
//     return 0;
// }
const int N=1e5+4;
int n,m,df[N],lo[N],sz[N];
vector<int>g[N];bool v[N];
ll ans;int cnt;
void dfs(int x,int f){ // same fucking solution as mine but mine doesn't work 
    df[x]=lo[x]=++cnt,sz[x]=1,v[x]=1;
    for(auto y:g[x])if(y!=f){
        if(!v[y])dfs(y,x),sz[x]+=sz[y];
        lo[x]=min(lo[x],lo[y]);
    }
    if(df[x]==lo[x])
        ans=max(ans,(ll)sz[x]*(n-sz[x]));
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
    int tc;cin>>tc;while(tc--){
        cin>>n>>m;for(int i=1;i<=n;i++)g[i].clear(),v[i]=0;
        while(m--){
            int u,v;cin>>u>>v;
            g[u].emplace_back(v),g[v].emplace_back(u);
        }
        ans=0,dfs(1,0),cout<<(ll)n*(n-1)/2-ans<<'\n';
    }
}