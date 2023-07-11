#include <bits/stdc++.h>
#define ll long long
#define INF 1e5

using namespace std; 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("SR1.in","r",stdin);
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0; i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a-1].push_back({b-1,c});
    }
    vector<int> dist(n,INF);
    priority_queue<pair<int,int>> q;
    int start = 0; 
    dist[0] = 0;
    q.push({0,start});
    while(!q.empty()){
        auto [cdist, node] = q.top();
        q.pop();
        if(cdist != dist[node]) continue;
        for(const pair<int,int> &i : adj[node]){
            if(cdist + i.second < dist[i.first]){
                dist[i.first] = cdist + i.second;
                q.push({dist[i.first], i.first});
            }
        }
    }
    for (int i = 0; i < n - 1; i++) { cout << dist[i] << ' '; }
	cout << dist[n - 1] << endl;
    return 0;
}