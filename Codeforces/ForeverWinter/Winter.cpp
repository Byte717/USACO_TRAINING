#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
bool valid = true;
pair<int,int> ans;

int dfs(int node,bool start=false){
    visited[node]= true;
    if(start){
        int total = 0, x = adj[node].size();
        for(int &n : adj[node]){
            total += dfs(n)-1;
        }
        if(total % x == 0){
            ans.first = x;
            ans.second = total / x;
            return 1;
        }else{
            valid = false;
            return -1;
        }
    }else{
        for(int &n : adj[node]){
            visited[n] = true;
        }
        return adj[node].size();
    }
}

void solve(){
    int n,m; cin >> n >> m;
    adj = vector<vector<int>>(n);
    visited = vector<bool>(n,false);
    for(int i = 0; i < m;i++){
        int u,v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    for(int start = 0; start < n;start++){
        fill(all(visited),false);
        valid = true;
        dfs(start,true);
        if(valid){
            bool alVis = true;
            for(int i = 0; i < n;i++){
                if(visited[i] == false){
                    alVis = false;
                    break;
                }
            }
            if(alVis) break;
        }
    }
    cout << ans.first << ' ' << ans.second << endl;

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("winter.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}