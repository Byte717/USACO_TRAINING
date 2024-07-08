#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define debug

#ifndef debug
    #pragma GCC optimize("O3","unroll-loops")
    #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#endif

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

map<int, int> colorSum;
vector<int> colors;
vector<vector<int>> adj;
vector<bool> vis;

void dfs(int node){
    if(vis[node]) return;
    vis[node] = true;
    int diff = 0;
    for(auto &x : adj[node]){
        if(colors[x] != colors[node]){
            diff++;
        }
    }
    colorSum[colors[node]] += diff;
    for(auto &x : adj[node]){
        dfs(x);
    }
}


void solve(){
    int n, m; cin >> n >> m;
    colors.resize(n);
    vis.resize(n);
    fill(all(vis), false);
    for(int i = 0; i < n;i++){
        cin >> colors[i];
        colorSum[colors[i]] = 0;
    }
    adj.resize(n);
    for(int i = 0; i < m;i++){
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    dfs(0);
    int ans = -1;
    int mxDiff = 0;
    for(auto &[color, val] : colorSum){
        if(val > mxDiff){
            ans = color;
            mxDiff = val;
        }
    }
    cout << (ans == -1 ? (*colorSum.begin()).first : ans) << endl;

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("graph.in","r",stdin);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}