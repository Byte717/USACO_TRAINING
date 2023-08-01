#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

vector<vector<ll>> adj;
vector<ll> leaves;
int dfs(int node, int parent){
    if(adj[node].size() == 1 && adj[node][0] == parent){
        leaves[node] = 1;
        return 1;
    }
    leaves[node] = 0;
    for(ll &n : adj[node]){
        if(n != parent){
            leaves[node] += dfs(n,node);
        }
    }
    return leaves[node];
}

void solve(){
    int n; cin >> n;
    adj = vector<vector<ll>>(n);
    leaves = vector<ll>(n,0);
    for(int i = 0; i < n-1;i++){
        ll x, y; cin >> x >> y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }
    dfs(0,-1);
    int q; cin >> q;
    while(q--){
        ll x, y; cin >> x >> y;
        x--; y--;
        cout << (leaves[x]*leaves[y]) << endl;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("apple.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}