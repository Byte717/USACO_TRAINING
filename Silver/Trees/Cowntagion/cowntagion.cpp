#include <bits/stdc++.h>

using namespace std; 

vector<vector<int>> graph;


int dfs(int node){
    
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("Cown.in","r",stdin);
    int n; cin >> n;
    graph = vector<vector<int>>(n);
    for(int i = 0; i < n;i++){
        int a, b; cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }

    return 0;
}