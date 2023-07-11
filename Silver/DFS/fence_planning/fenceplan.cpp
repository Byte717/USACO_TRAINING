#include <bits/stdc++.h>
#define ll long long 

using namespace std; 

vector<vector<int>> graph;
vector<bool> visited;
vector<pair<int,int>> currentGroup;
vector<vector<pair<int,int>>> groups;
vector<pair<int,int>> coordinates;

void dfs(int node){
    if(visited[node]){
        return;
    }
    visited[node] = true;
    currentGroup.push_back(coordinates[node]);
    for(int i = 0; i < graph[node].size();i++){
        if(!visited[graph[node][i]]){
            dfs(graph[node][i]);
        }
    }
}


int main(){
    freopen("fenceplan.in","r", stdin);
    int n, m; cin >> n >> m;
    coordinates.resize(n);
    graph.resize(n);
    visited.resize(n);
    for(int i = 0; i < n;i++) cin >> coordinates[i].first >> coordinates[i].second;
    for(int i = 0; i < m;i++){
        int a,b; 
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    fill(visited.begin(),visited.end(),false);
    for(int i = 0; i < n;i++){
        currentGroup.clear();
        if(!visited[i]){
            dfs(i);
            groups.push_back(currentGroup);
        }
    }
    int MinPerimeter = INT32_MAX;
    for(int i = 0; i < groups.size();i++){
        int maxX = -1, minX = INT32_MAX, maxY = -1, minY = INT32_MAX;
        for(int j = 0; j < groups[i].size();j++){
            int x = groups[i][j].first, y = groups[i][j].second;
            maxX = max(maxX, x);
            minX = min(minX, x);
            maxY = max(maxY, y);
            minY = min(minY, y);
        }
        MinPerimeter = min(MinPerimeter,2*(maxX-minX) + 2*(maxY - minY));
    }
    cout << MinPerimeter << endl;
}