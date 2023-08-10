#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

/*
solution: use tree dp

dp[i] is the number of passes it takes to add ith node
for an edge, if one node is added in(u,v), then dp[v] = dp[u] + 1;
then id represents the order of the appearance in the text
if the current edge's connection comes before the idx of the current node, then we add

What I learned Drawing Trees:
- find how to optimize problems with using base cases for what is visited
- like id represents 0 if the node was not added

*/




const int NMAX = 2e5+5;
int dp[NMAX], id[NMAX];
vector<pair<int,int>> edg[NMAX];
void dfs(int node){
    for(auto &[n, idx] : edg[node]){
        if(dp[n] == 0){
            dp[n] = dp[node] + (idx <= id[node]);
            id[n] = idx;
            dfs(n);
        }
    }
}
void solve(){
    int n; cin >> n;
    for(int i = 1; i<= n;i++){
        dp[i] = 0;
        id[i] = 0;
        edg[i].clear();
    }
    for(int i = 1; i < n;i++){
        int x, y; cin >> x >> y;
        edg[x].push_back({y,i});
        edg[y].push_back({x,i});
    }
    dp[1] = 1;
    dfs(1);
    int ans = 0; 
    for(int i = 1; i<=n;i++) ans = max(ans,dp[i]);
    cout << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("drawtree.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}