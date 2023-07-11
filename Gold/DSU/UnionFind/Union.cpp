#include <iostream>
#include <cstdio>
#include <vector>

using namespace std; 

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node){
    if(visited[node])return;
    visited[node] = true; 
    for(int n : graph[node]){
        dfs(n);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("union.in","r",stdin);
    int n, q; cin >> n >> q;
    graph = vector<vector<int>>(n);
    visited = vector<bool>(n,false);
    for(int i = 0; i < q;i++){
        int t, u, v;
        cin >> t >> u >> v; 
        if(t == 1){
            fill(visited.begin(),visited.end(), false);
            dfs(u);
            (visited[u] && visited[v]) ? cout << 1 << endl : cout << 0 << endl; 
        }else{
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    return 0;
}