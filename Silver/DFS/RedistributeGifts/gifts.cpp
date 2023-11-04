#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x),end(x)
using namespace std; 

/*
first and foremost, if cow 1 prefers, say 2,3,1,4, then 4 doesn't matter. take cow 1's instead.
so now imagine we draw an edge from a node and all of the nodes it prefers before its own.
this will be a directed graph, and therefore, wherever we have a cycle, we can just use those.
this means we need to find the strongly connected components.

so we dfs first time, and note down the order in which we vis, by noting the ending time.
then we reverse the edges, and for each connected component, we look at each node.
if we see that one of it's prefered gifts is in the same component, then we can swap them.

What I learned Redistributing gifts:
    - kosaraju's algorithm
    - SCCs can be used to solve graph problems.

*/


const int N = 501;
vector<int> adj[N], radj[N];
vector<bool> vis(N,false), vis2(N,false);
vector<int> path;
set<int> comp;

void dfs(int node){
    vis[node] = true;
    for(int &i : adj[node]){
        if(!vis[i]) dfs(i);
    }
    path.push_back(node);
}

void dfs2(int node){
    vis2[node] = true;
    for(int i : radj[node]){
        if(!vis2[i]) dfs2(i);
    }
    comp.insert(node);
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("gifts.in","r",stdin);
    int n; cin >> n;
    for(int i = 1; i <= n;i++){
        adj[i].resize(n);
        for(int j = 0; j < n;j++){
            cin >> adj[i][j];
        }

        while(adj[i].back() != i) adj[i].pop_back();
        for(int j : adj[i]) radj[j].push_back(i);
    }

    for(int i = 1; i <= n;i++){
        if(!vis[i]) dfs(i);
    }
    reverse(all(path));
    vector<int> ans(n+1);
    for(int &i : path){
        if(!vis2[i]){
            dfs2(i);

            for(int j : comp){
                for(int k : adj[j]){
                    if(comp.count(k)){
                        ans[j] = k;
                        break;
                    }
                }
            }
            comp.clear();
        }
    }
    for(int i = 1; i <= n;i++) cout << ans[i] << endl;

    return 0;
}