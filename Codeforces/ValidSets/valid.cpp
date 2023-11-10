#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

vector<vector<int>> adj;
vector<int> a;
vector<int> dp;
int d;
void dfs(int node, int parent, int root){
    dp[node] = 1;
    for(auto &i : adj[node]){
        if(i != parent){
            if((a[i] < a[root]) || (a[i] > a[root] + d)) continue; // this node cannot be part of the set, as the root is our minimum
            if((a[i] == a[root]) && (i < root)) continue; // a set with i, root has already been counted, and this current set  already has the a[i] value of the root
            dfs(i,node,root);
            dp[node] *= dp[i]+1;
            dp[node] %= MOD;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    
    int n; cin >> d >> n;
    a = vector<int>(n);
    adj = vector<vector<int>>(n);
    dp = vector<int>(n,0);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }

    for(int i = 0; i < n-1;i++){
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    int res = 0;
    for(int i = 0; i < n;i++){
        fill(all(dp),0);
        dfs(i,i,i);
        res += dp[i];
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}