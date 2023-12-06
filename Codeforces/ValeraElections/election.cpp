#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

vector<vector<pair<int,int>>> adj;
vector<bool> needsFix;
vector<int> dp;

void dfs(int node,int parent){
    dp[node] = 0;
    if(needsFix[node]) dp[node]++;
    for(auto &[x,y] : adj[node]){
        if(x != parent[node]){
            dfs(x,node);
            dp[node] += dp[x];
        }
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;

    adj = vector<vector<pair<int,int>>>(n);
    dp = vector<int>(n);
    needsFix = vector<bool>(n,false);
    for(int i = 0; i < n-1;i++){
        int a, b, u;cin >> a >> b >> u;
        a--; b--;
        adj[a].push_back({b,u});
        adj[b].push_back({a,u});
        needsFix[a] = true;
        needsFix[b] = true;
    }

    dp[0] = 0;
    dfs(0,-1);
    vector<int> ans;
    for(int i = 0; i < n;i++){
        if(needsFix[i] && dp[i] == 1){
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size();i++){
        cout << ans[i] << endl;
    }
    return 0;
}