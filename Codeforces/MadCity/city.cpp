#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int n, a, b;
vector<vector<int>> adj;

vector<bool> vis;
vector<int> distM, distV;
int start = -1;

void dfs(int node, int parent){
    vis[node] = true;
    for(auto &i : adj[node]){
        if(vis[i] && i != parent){
            start = i;
            return;
        }else if(i != parent && !vis[i]){
            dfs(i,node);
        }
    }
}

void solve(){
    cin >> n >> a >> b;
    if(a==b){
        cout << "NO" << endl;
    }
    adj = vector<vector<int>>(n);
    distM = vector<int>(n,INT32_MAX), distV = vector<int>(n,INT32_MAX);
    vis = vector<bool>(n,false);
    for(int i = 0; i < n;i++){
        int u,v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(a);
    distM[a] = 0;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        if(vis[top]) continue;

        vis[top] = true;
        for(int & i : adj[top]){
            if(!vis[i]){
                distM[i] = distM[top] + 1;
            }
        }
    }

    vis = vector<bool>(n,false);
    distV[b] = 0;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        if(vis[top]) continue;

        vis[top] = true;
        for(int & i : adj[top]){
            if(!vis[i]){
                distV[i] = distV[top] + 1;
            }
        }
    }
    vis = vector<bool>(n,false);
    dfs(0,-1);
    if(distM[start] <= distV[start]){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("city.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}