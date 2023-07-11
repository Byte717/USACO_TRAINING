#include <bits/stdc++.h>

using namespace std; 

string cows;
vector<vector<int>> graph;
vector<bool> visited;
int a, b; char target;
vector<int> ans;
bool found = false;


void dfs(int node, bool currentOK){
    if(visited[node]) return;
    if(cows[node] == target) currentOK = true;
    if(node == b){
        if(currentOK){
            found = true;
            return;
        }else return;
    }
    visited[node] = true;
    for(auto i : graph[node]){
        dfs(node, currentOK);
    }

}
 
int main(){
    freopen("milkvisits.in","r",stdin);
    int n, m; cin >> n >> m;
    cin >> cows;
    graph.resize(n);
    visited = vector<bool>(n,false);
    ans = vector<int>(n,0);
    for(int i = 0;i < n-1;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    for(int i = 0; i < m;i++){
        cin >> a >> b >> target;
        --a; --b;
        if(cows[a] == target) ans[i] = 1;
        else if(cows[b] == target) ans[i] = 1;
        else ans[i] = 0;
        if(a != b){
            dfs(a, false);
            if(found){
                found = false;
                ans[i] = 1;
            }
            fill(visited.begin(), visited.end(), false);
        }
    }
    for(int i = 0; i < m;i++){
        cout << ans[i];
    }
    cout << endl;
    return 0;
}