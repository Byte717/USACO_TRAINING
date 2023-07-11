#include <bits/stdc++.h>

using namespace std; 


vector<vector<int>> adj;
vector<bool> visited;

void bfs(int node){
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        visited[curr] = true;
        for(int n : adj[node]){
            if(!visited[n]) q.push(n);
        }
    }
}

void dfs(int node){
    if(visited[node]) return;
    visited[node] = true;
    for(int n : adj[node]) dfs(n);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("roads.in","r",stdin);
    int n, m; cin >> n >> m; 
    adj = vector<vector<int>>(n);
    visited = vector<bool>(n,false);
    for(int i = 0; i < m;i++){
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    vector<int> ans;
    for(int i = 0;i < n;i++){
        if(!visited[i]){
            ans.push_back(i);
            dfs(i);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size();i++){
        
    }
    return 0;
}