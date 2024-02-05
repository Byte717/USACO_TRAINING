#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int k;
vector<vector<ll>> dp, adj;
ll tot = 0;
void dfs(int node,int parent){
    dp[node][0] = 1;
    for(auto u : adj[node]){
        if(u == parent) continue;
        dfs(u,node);
        for(int i = 0; i < k;i++){
            tot += dp[node][i]*dp[u][k-i-1];
        }
        for(int i = 0; i < k;i++){
            dp[node][i+1] += dp[u][i];
        }
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int n; cin >> n >> k;
    dp = vector<vector<ll>>(n+1, vector<ll>(k+1,0));
    adj.resize(n+1);
    for(int i = 0; i < n-1;i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    cout << tot << endl;
    return 0;
}