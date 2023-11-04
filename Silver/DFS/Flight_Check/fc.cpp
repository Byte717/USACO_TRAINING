#include <bits/stdc++.h>

using namespace std; 

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node){
    if(visited[node]){
        return;
    }
    visited[node] = true;
    for(int i = 0; i < graph[node].size();i++){
        if(!visited[graph[node][i]]){
            dfs(graph[node][i]);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("fc.in","r",stdin);
    int n, m; cin >> n >> m;
    graph.resize(n);
    visited.resize(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; 
        graph[--a].push_back(--b);
    }
    for(int i = 0; i < n;i++){
        fill(visited.begin(),visited.end(),false);
        dfs(i);
        for(int j = 0; j < n;j++){
            if(visited[j] == false){
                cout << "NO" << endl;
                cout << i+1 << " " << j+1 << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;

    
    return 0;
}