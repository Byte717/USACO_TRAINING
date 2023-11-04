#include <bits/stdc++.h>
#define ll long long

using namespace std; 

vector<set<int>> adj;
set<int> visited;

int dfs(int node){
    if(visited[node]){
        return 0;
    }
    visited[node] = true;
    int numNodes = 1;
    for(int n : adj[node]){
        numNodes += dfs(n);
    }
    return numNodes;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("cc.in","r",stdin);
    int n,m; cin >> n >> m;
    adj = vector<set<int>>(n);
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            adj[i].insert(j);
        }
    }

    for(int i = 0; i < m;i++){
        int a, b; cin >> a >> b;
        adj[--a].erase(--b);
        adj[b].erase(a);
    }

    int numComponents = 0;
    vector<int> componentSize;
    for(int i = 0; i < n;i++){
        if(visited.find(i)){
            numComponents++;
            componentSize.push_back(dfs(i));
        }
    }
    sort(componentSize.begin(), componentSize.end());
    cout << numComponents << endl;
    for(int i : componentSize){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}