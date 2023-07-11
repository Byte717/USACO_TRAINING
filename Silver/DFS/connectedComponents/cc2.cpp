#include <bits/stdc++.h>
#define ll long long

using namespace std; 




int n, m;
vector<unordered_set<int>> adj;
set<int> unvisited;
int sz[200000];
int cur=0;
void dfs(int node){
    sz[curr]++;
    auto it = unvisited.begin();
    while(it != unvisited.end()){
        if(adj[node].count(*it)){
            it++;
        }else{
            int last = *it;
            unvisited.erase(it);
            dfs(last);
            it = unvisited.upper_bound(last);
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("cc.in","r",stdin);
    cin >> n >> m;
    adj = vector<unordered_set<int>>(n);

    for(int i = 0; i < m;i++){
        int a, b; cin >> a >> b;
        adj[--a].insert(--b);
        adj[b].insert(a);
    }
    for(int i = 0;i < n;i++) unvisited.insert(i);
    for(int i = 0; i < n;i++){
        auto idx = unvisited.find(i);
        if(idx != unvisited.end()){
            unvisited.erase(i);
            dfs(i);
            curr++;
        }
    }
    cout << cur << endl;
	sort(sz, sz + cur);
	for (int i = 0; i < cur; i++) { cout << sz[i] << ' '; }
	cout << endl;
    return 0;
}