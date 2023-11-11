#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;
int n,k; 

vector<int> marked;

vector<vector<int>> adj;
vector<bool> vis;

void dfs(int node, int parent, vector<int>&d){
    if(parent != -1) d[node] = d[parent] + 1;
    for(auto &v : adj[node]){
        if(v != parent){
            dfs(v,node,d);
        }
    }
}



void solve(){
    cin >> n >> k;
    marked = vector<int>(k);
    for(int i = 0; i < k;i++){
        cin >> marked[i];
        marked[i]--;
    }

    adj = vector<vector<int>>(n);
    vis = vector<bool>(n,false);

    for(int i = 0; i < n-1;i++){
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    if(k == 1){
        cout << 0 << endl;
        return;
    }
    vector<int> d1(n);
    dfs(marked[0],-1, d1);
    int mx = marked[0];
    for(int e: marked){
        if(d1[e] > d1[mx]) mx = e;
    }
    vector<int> d2(n);
    dfs(mx, -1,d2);
    mx = marked[0];
    for(int e : marked){
        if(d2[e] > d2[mx]) mx = e;
    }
    cout << (d2[mx] + 1)/2 << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("minMax.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}