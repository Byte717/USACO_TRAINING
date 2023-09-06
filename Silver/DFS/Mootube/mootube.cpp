#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

vector<vector<pair<int,ll>>> adj;
vector<bool> vis;
int ans = 0;
ll globalK = -1;
int start;

void dfs(int currNode, ll rel){
    vis[currNode] = true;
    for(auto &[node, y] : adj[currNode]){
        if(!vis[node] && min(rel, y) >= globalK){
            ans++;
            dfs(node,min(rel,y));
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("mootube.in","r",stdin);
    freopen("mootube.out","w",stdout);
    int n, q; cin >> n >> q;
    adj = vector<vector<pair<int,ll>>>(n);
    vis = vector<bool>(n,false);
    for(int i = 0; i < n-1;i++){
        int a, b; ll c;
        cin >> a >> b >> c;
        adj[--a].push_back({--b,c});
        adj[b].push_back({a,c});
    }
    while(q--){
        ll k;
        cin >> k >> start;
        globalK = k;
        fill(all(vis),false);
        ans = 0;
        dfs(start-1, k);
        cout << ans << endl;
    }
    return 0;
}