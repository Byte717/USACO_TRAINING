#include <bits/stdc++.h>
#define ll long long
#define INF 1e5

using namespace std; 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("cs.in","r",stdin);
    int n, m; cin >> n >> m; 
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    for(int i = 0; i < m;i++){
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
        indegree[b]++;
    }
    queue<int> q;
    for(int i = 0; i < n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<bool> visited(n,false);
    vector<int> order;
    while(!q.empty()){
        int curr = q.front(); q.pop();
        order.push_back(curr);
        if(!visited[curr]){
            visited[curr] = true;
            for(int n : adj[curr]){
                q.push(n);
            }
        }
    }
    if(order.size() != n){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for(int i = 0; i < n;i++){
        cout << order[i] << " ";
    }
    cout << endl;
    return 0;
}