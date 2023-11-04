#include <bits/stdc++.h>

using namespace std; 

vector<vector<int>> graph;
vector<bool> visited;


void dfs(int node){
    if(visited[node]) return;
    visited[node] = true;
    for(auto x : graph[node]){
        if(!visited[x]) dfs(x);
    }
    return;
}


int main(){
    // freopen("input.in","r",stdin);
    int n; cin >> n;
    graph = vector<vector<int>>(n);
    visited = vector<bool>(n,false);
    for(int i = 0; i < n;i++){
        int a; cin >> a;
        graph[i].push_back(--a);
        graph[a].push_back(i);
    }
    int ans = 0;
    for(int i = 0; i < n;i++){
        if(!visited[i]){
            dfs(i);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}