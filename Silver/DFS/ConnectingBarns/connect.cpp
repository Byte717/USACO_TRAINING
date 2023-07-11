#include <bits/stdc++.h>
#define ll long long

using namespace std; 


vector<vector<int>> graph;
vector<int> group;
vector<vector<int>> components;


ll cost(int a, int b){
    ll dist = 1e18; 
    for(auto x : components[a]){
        int index = lower_bound(components[b].begin(),components[b].end(), x) - components[b].begin();
        if(index > 0) dist = min((int)dist, abs(components[b][index-1]));
        if(index < components[b].size()) dist = min((int)dist, abs(components[b][index]));
    }
    return dist*dist;
}

ll cost2(int a, int b){
    ll dist = 1e5;
    for(int x : components[a]){
        int closest = lower_bound(components[b].begin(), components[b].end(0), x) - components[b].begin();
        
    }
}


void dfs(int node, int grp){
    if(group[node] != -1) return;
    group[node] = grp;
    for(auto x : graph[node]){
        if(group[x] == -1) dfs(x, grp);
    }
}


void solve(){
    int n,m; cin >> n >> m;
    group = vector<int>(n,-1);
    graph = vector<vector<int>>(n);
    for(int i = 0; i < m;i++){
        int a, b; cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    int currentGroup = -1;
    for(int i = 0; i < n;i++){
        if(group[i] == -1){
            dfs(i,++currentGroup);
        }
    }
    components = vector<vector<int>>(currentGroup+1);
    for(int i = 0; i < n;i++){
        components[group[i]].push_back(i);
    }

    if(group[0] == group[n-1]){
        cout << 0 << endl;
        return;
    }
    ll ret = cost(group[0], group[n-1]);
    for(int i = 1; i < currentGroup;i++){
        ret = min(ret, cost(i,group[0]) + cost(i, group[n-1]));
    }
    cout << ret << endl;
    return;
}

int main(){
    // freopen("connect.in","r",stdin);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}