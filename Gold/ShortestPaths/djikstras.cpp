

void dks(vector<vector<pair<int,int>>> adj, int n){
    vector<bool> vis(n);
    vector<int> dist(n, 1e9);
    priority_queue<pair<int,int>> q; // {-d,x}, distance to node x is d
    q.push({0,x});
    while(!q.empty()){
        auto &[d, x] = q.top();
        d = -d;

        if(vis[x]) continue;

        for(auto &[node, dist] : adj[x]){
            if(dist[x] + dist < dist[node]){
                dist[node] = dist[x] + dist;
                q.push({-dist[node], node});
            }
        }
    }
}