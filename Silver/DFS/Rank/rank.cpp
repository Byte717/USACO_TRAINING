#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

vector<vector<int>> adj, radj;
vector<bool> vis, vis2;
vector<int> path;
set<int> inLoop;

void dfs1(int node){
    vis[node] = true;
    for(auto i : adj[node]){
        if(!vis[i]) dfs1(i);
    }
    path.push_back(node);
}

void dfs2(int node){
    vis2[node] = true;
    for(auto i : radj[node]){
        if(!vis2[i]) dfs2(i);
    }
    inLoop.insert(node);
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n, k; cin >> n >> k;
    adj.resize(n,{}); radj.resize(n,{});
    vis.resize(n, false); vis2.resize(n, false);
    for(int i = 0; i < k;i++){
        int a, b, sa, sb; cin >> a >> b >> sa >> sb; 
        if(sa > sb){// a beats b
            adj[--b].push_back(--a);
            radj[a].push_back(b);
        }else{
            adj[--a].push_back(--b);
            radj[b].push_back(a);
        }
    }
    for(int i = 0; i < n;i++){
        if(!vis[i]){
            dfs1(i);
        }
    }
    reverse(all(path));
    int ans = 0;
    for(auto &i : path){
        if(!vis2[i]){
            dfs2(i);
            ans += inLoop.size();
            inLoop.clear();
        }
    }
    cout << ans << endl;
    return 0;
}