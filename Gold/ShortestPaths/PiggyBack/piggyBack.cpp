#include <bits/stdc++.h>

using namespace std;

int b, e, p, n, m;

vector<vector<int>> graph; 
vector<bool> visited;
vector<int> bessie, elsie, combined;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("piggyback.in","r",stdin);
    freopen("piggyback.out","w",stdout);
    cin >> b >> e >> p >> n >> m;
    graph = vector<vector<int>>(n);
    visited = vector<bool>(n,false);
    bessie = vector<int>(n, 1e5); elsie = vector<int>(n,1e5); combined = vector<int>(n,1e5);
    for(int i = 0; i < m;i++){
        int a, b; cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    bessie[0] = 0;
    elsie[1] = 0;
    combined[n-1] = 0;

    queue<pair<int, int>> q;
    q.push({0,0});
    while(!q.empty()){
        int node = q.front().first, source = q.front().second;
        q.pop();
        if(!visited[node]){
            if(node == 0){
                bessie[0] = 0;
            }else{
                bessie[node] = bessie[source] + b;
            }
            visited[node] = true;
            for(int n : graph[node]){
                q.push({n,node});
            }
        }
    }
    q = queue<pair<int,int>>();
    fill(visited.begin(),visited.end(),false);
    q.push({1,1});
    while(!q.empty()){
        int node = q.front().first, source = q.front().second;
        q.pop();
        if(!visited[node]){
            if(node == 1){
                elsie[1] = 0;
            }else{
                elsie[node] = elsie[source] + e;
            }
            visited[node] = true;
            for(int n : graph[node] ){
                q.push({n,node});
            }
        }
    }

    q = queue<pair<int,int>>();
    fill(visited.begin(),visited.end(),false);
    q.push({n-1,n-1});
    while(!q.empty()){
        int node = q.front().first, source = q.front().second;
        q.pop();
        if(!visited[node]){
            if(node == n-1){
                combined[n-1] = 0;
            }else{
                combined[node] = combined[source] + p;
            }
            visited[node] = true;
            for(int n : graph[node] ){
                q.push({n,node});
            }
        }
    }

    int ans = elsie[n-1] + bessie[n-1];
    for(int node = 0; node <= n-1;node++){
        ans = min(ans, elsie[node]+bessie[node]+combined[node]);
    }
    cout << ans << endl;
    return 0;
}