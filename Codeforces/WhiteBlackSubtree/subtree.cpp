#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

/*
what I learned White Black Subtrees:
    - tree dp can be used to count solutions for subtrees.

*/

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<int> dp(n,0);
    for(int i = 1; i < n;i++){
        int x; cin >> x;
        x--;
        adj[x].push_back(i);
    }
    string colors; cin >> colors;
    int res = 0;
    function<int(int)> dfs = [&](int node){
        int bal = (colors[node] == 'B') ? -1 : 1; 
        if(adj[node].size() == 0) return bal;
        for(int i : adj[node]){
            bal += dfs(i);
        }
        if(bal == 0) res++;
        return bal;
    };
    dfs(0);
    cout << res << endl;

}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("subtree.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}