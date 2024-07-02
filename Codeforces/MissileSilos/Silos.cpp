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
    int n, m, s; cin >> n >> m >> s;
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0; i < m;i++){
        int v, u, w; cin >> v >> u >> w; 
        adj[--v].push_back({--u,w});
        adj[u].push_back({v,w});
    }
    int l; cin >> l;
    vector<int> dist(n, 1e9);
    priority_queue<pair<int,int>> pq; // negative dist, node
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()){
        auto [cur, node] = pq.top();
        pq.pop();
        cur = -cur;
        for(auto &[x, w] : adj[node]){
            if(dist[x] > cur + w){
                dist[x] = cur + w;
                pq.push({-dist[x], x});
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n;i++){
        for(auto [node, w] : adj[i]){
            if(dist[i] < l && l - dist[i] < w && w -(l-dist[i]) + dist[node] > l){
                ans++;
            }
            else if(dist[node] < l && l - dist[node] < w && w - (l-dist[node]) + dist[i] > l){
                ans++;
            }
            else if(dist[node] < l && dist[i] < l && dist[node] + dist[i] + w == 2*l){
                ans++;
            }
            else if(dist[i] == l){
                ans++;
            }
        }
    }
    cout << (ans > 1 ? ans-1 : ans) << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("silos.in","r",stdin);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}