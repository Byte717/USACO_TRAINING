#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// #pragma GCC optimize("O3","unroll-loops")
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


void solve(){
    int n, m; cin >> n >> m;
    map<pair<int,int>, int> edges;
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0; i < m;i++){
        int u, v, w; cin >> u >> v >> w;
        adj[--u].push_back({--v,w});
        adj[v].push_back({u,w});
        edges[{u,v}] = w;
        edges[{v,w}] = w;
    }
    vector<int> slowness(n);
    for(int i = 0; i < n;i++){
        cin >> slowness[i];
    }
    vector<int> last(n,-1);

    vector<bool> vis(n);
    vector<int> dist(n, 1e9);
    dist[0] = 0;
    priority_queue<pair<int,int>> q; // {-d,x}, distance to node x is d
    q.push({0,0});
    while(!q.empty()){
        auto p = q.top(); q.pop();
        int d = p.first, x = p.second;
        d = -d;

        if(vis[x]) continue;

        for(auto &[node, dist2] : adj[x]){
            if(dist[x] + dist2 < dist[node]){
                dist[node] = dist[x] + dist2;
                last[node] = x;
                q.push({-dist[node], node});
            }
        }
    }
    vector<int> path;
    int cur = n-1;
    while(cur != 0){
        path.push_back(cur);
        cur = last[cur];
    }
    path.push_back(0);
    reverse(all(path));
    int curBike = slowness[0];
    int ans = 0;
    for(int i = 0; i < path.size()-1;i++){
        if(i == 0){
            ans += curBike*edges[{0,path[1]}];
            continue;
        }
        if(slowness[i] < curBike){
            curBike = slowness[i];
        }
        ans += curBike*edges[{path[i],path[i+1]}];
    }
    cout << ans << endl;

}




int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("cycles.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}