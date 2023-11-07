#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;>

const ll INF = 1e18;
const ll MOD = 1e9+7;

vector<vector<int>> adj;
vector<vector<ll>> dp;

void dfs(int node, int parent){
    for(auto i : adj[node]){
        if(i != parent){
            dfs(i,node);
            dp[node][0] *= dp[i][1] + dp[i][2];
            dp[node][1] *= dp[i][0] + dp[i][2];
            dp[node][2] *= dp[i][0] + dp[i][1];

            for(int color = 0; color < 3;color++){
                dp[node][color] %= MOD;
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n,k; cin >> n >> k;
    adj = vector<vector<int>>(n);
    dp = vector<vector<ll>>(n+1, vector<ll>(3));
    for(int i = 0; i <n-1;i++){
        int x, y; cin >> x >> y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }
    for(int i = 1;i <= n;i++){
        dp[i][0] = 1;
        dp[i][1] = 1;
        dp[i][2] = 1;
    } 

    for(int i = 0; i < k;i++){
        int node, color; cin >> node >> color;
        for(int c = 0; c < 3;c++){
            dp[node][c] = 0;
        }
        dp[node][color-1] = 1;
    }
    dfs(0,-1);
    cout << (dp[0][0] + dp[0][1] + dp[0][2]) % MOD << endl;
    return 0;
}