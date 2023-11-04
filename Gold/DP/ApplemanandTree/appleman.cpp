#include <bits/stdc++.h>
#define INF 1e18
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef unsigned long long ll;

using namespace std;
const ll MOD = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("appleman.in","r",stdin);
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 1; i < n;i++){
        int pi; cin >> pi;
        adj[pi].push_back(i);
        adj[i].push_back(pi);
    }
    vector<int> color(n);
    for(int i = 0; i < n;i++){
        cin >> color[i];
    }
    ll dp[n+1][2];
    function<void(int,int)> dfs = [&](int v, int parent){
        dp[v][0] = 1;
        dp[v][1] = 0;
        for(int &u : adj[v]){
            if(u != parent){
                dfs(u, v);
                dp[v][1] *= dp[u][0];
                dp[v][1] += dp[v][0] *dp[u][1];
                dp[v][0] *= dp[u][0];
                dp[v][1] = dp[v][1] % MOD;
                dp[v][0] = dp[v][0] % MOD;
            }
        }
        if(color[v] == 1){
            dp[v][1] = dp[v][0];
        }else{
            dp[v][0] += dp[v][1];
        }

    };
    dfs(0,-1);
    cout << dp[0][1] << endl;
    return 0;
}