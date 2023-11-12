#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;
vector<int> calcDist(vector<vector<int>> const &g) {
  vector<int> dist(g.size(), -1);
  dist[0] = 0;
  queue<int> pq;
  pq.push(0);
  while (!pq.empty()) {
    int u = pq.front();
    pq.pop();
    for (int v : g[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        pq.push(v);
      }
    }
  }
  return dist;
}

void dfs(int u, vector<vector<int>> &adj, vector<int> &dist, vector<int> &dp, vector<bool> &used){
    used[u] = true;
    dp[u] = dist[u];
    for(int v : adj[u]){
        if(!used[v] && dist[u] < dist[v]){
            dfs(v,adj,dist,dp,used);
        }
        if(dist[u] < dist[v]){
            dp[u] = min(dp[u], dp[v]);
        }else{
            dp[u] = min(dp[u], dist[v]);
        }
    }
}


void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m;i++){
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
    }
    vector<int> dist = calcDist(adj);

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}