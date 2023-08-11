#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<bool> vis(n,false);

    bool bad = false;
    for(int i = 0; i < n;i++){
        int x, y; cin >> x >> y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
        if(adj[x].size() > 2 || adj[y].size() > 2|| x == y) bad = true;
    }
    if(bad){
        cout << "NO" << endl;
        return;
    }
    function<int(int)> dfs = [&](int node){
        vis[node] = true;
        for(int &n : adj[node]){
            if(!vis[n]){
                return dfs(n) + 1;
            }
        }
        return 1;
    };

    for(int i = 0; i < n;i++){
        if(!vis[i]){
            if(dfs(i)%2){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("sets.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}