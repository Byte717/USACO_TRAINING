#include <bits/stdc++.h>

using namespace std; 

vector<vector<int>> graph;
vector<int> infected;
int days = 0;

void dfs(int node, int parent){
    // if(visited[node]){return;}
    // visited[node] = true;
    while(infected[node] < graph[node].size()){
        infected[node] *= 2;
        days++;
    }
    for(int &n : graph[node]){
        if(n != parent){
            infected[n]++;
            infected[node]--;
            dfs(n,node);
            days++;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("cown.in","r",stdin);
    int n; cin >> n;
    graph = vector<vector<int>>(n);
    infected = vector<int>(n,0);
    infected[0] = 1;
    for(int i = 0; i < n-1;i++){
        int a, b; cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    for(int i = 0; i < n;i++){
        if(infected[i] == 0){
            days++;
        }
    }
    cout << days << endl;
    return 0;
}