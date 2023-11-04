#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
vector<int> dist;
vector<bool> visited;
int n, m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("message.in","r",stdin);
    cin >> n >> m;
    graph.resize(n);
    dist.resize(n);
    visited.resize(n);
    vector<int> lastVisited = vector<int>(n,-1);
    for(int i = 0; i < m;i++){
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }

    
    fill(dist.begin(),dist.end(), 1e5);
    dist[0] = 0;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        int top = q.front().first, source = q.front().second;
        q.pop();
        if(!visited[top]){
            if(top == 0){
                dist[0] = 0;
                lastVisited[0] = 0;
            }else if(dist[top] > dist[source] + 1){
                dist[top] = dist[source] + 1;
                lastVisited[top] = source;
            }
            visited[top] = true;
            for(int n : graph[top]){
                q.push({n,top});
            }
        }
    }
    if(dist[n-1] == 1e5){
        cout << "IMPOSSIBLE" << endl;
    }else{
        cout << dist[n-1] << endl;
        vector<int> path;
        int currentNode = n-1;
        while(currentNode != 0){
            path.push_back(currentNode + 1);
            currentNode = lastVisited[currentNode];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        for(int i : path){
            cout << i << " ";
        }
    }


    return 0;
}