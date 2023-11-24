#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n, m, t; cin >> n >> m >> t; 
    vector<int> fields(n);
    for(int i = 0; i < n;i++){
        cin >> fields[i];
    }
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0; i < m;i++){
        int u,v,c; cin >> u >> v >> c;
        adj[--u].push_back({--v,c});
        adj[v].push_back({u,c});
    }
    vector<int> cost(n,INT32_MAX);
    vector<int> prev(n,INT32_MAX);
    priority_queue<pair<int,int>> pq;
    cost[0] = 0;
    while(!pq.empty()){
        auto &[d,node] = pq.top();
        pq.pop();
        d = -d;
        if(d != cost[node]) continue;
        for(auto &[n, weight] : adj[node]){
            if(d + weight < cost[n]){
                cost[n] = d + weight;
                pq.push({d + weight, n});
                prev[n] = node;
            }else if(d + weight == cost[n] && node < prev[n]){
                prev[n] = node;
                pq.push({d+weight, n});
            }
        }
    }

    vector<ll> occ(n);
    for(int i = 0; i < n;i++){
        int cur = i;
        while(cur != INT32_MAX){
            occ[cur] += fields[i];
            cur = prev[cur];
        }
    }

    ll ans = 0;
    for(int i = 0; i < n;i++){
        ans = max(ans,(occ[i]*(cost[i]-t)));
    }
    cout << ans << endl;
    return 0;
}