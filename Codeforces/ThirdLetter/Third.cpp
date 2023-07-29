#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct Condition{
    int a, b;
    ll d;
};

int n, m; 
vector<vector<pair<int,ll>>> adj;
vector<bool> visited;
vector<ll> val;



void dfs(int node){
    if(visited[node]){
        return;
    }
    visited[node] = true;
    for(auto &[n,w] : adj[node]){
        val[n] = val[node] + w;
        dfs(n);
    }
}



void solve(){
    cin >> n >> m;
    adj = vector<vector<pair<int,ll>>>(n);
    visited = vector<bool>(n,false);
    val = vector<ll>(n,0);
    vector<Condition> edges;
    for(int i = 0; i < m;i++){
        int a, b; cin >> a >> b;
        ll d; cin >> d;
        adj[--a].push_back({--b, d});
        adj[b].push_back({a,-d});
        edges.push_back({a,b,d});
    }
    for(int i = 0; i < n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    for(auto &x : edges){
        if(val[x.a] + x.d != val[x.b]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;    
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("third.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}