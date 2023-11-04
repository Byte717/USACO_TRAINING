#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;
    int sum = 0;
    vector<int> hay(n);
    for(int i = 0; i < n;i++){
        cin >> hay[i];
        sum += hay[i];
    }

    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1;i++){
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    vector<int> need(n);
    for(int i = 0; i < n;i++){
        need[i] = (hay[i]) - (sum/n);
    }

    vector<int> subTreeSum(n);

    function<int(int,int)> treeDp = [&](int node, int parent){
        subTreeSum[node] = need[i];
        for(auto u : adj[node]){
            if(u != parent){
                subTreeSum[node] += treeDp(u, node);
            }
        }
        return subTreeSum[node];
    };
    treeDp(0,-1);
    vector<pair<pair<int,int>,int>> directions;
    function<void(int,int)> dfs = [&](int node, int parent){
        for(auto u : adj[node]){
            if(subTreeSum[u] >= 0 && u != parent){
                directions.push_back({{u, node}, subTreeSum[u]});
                dfs(u);
            }
        }
        for(auto u : adj[node]){
            if(subTreeSum[u] < 0 && u != parent){
                directions.push_back({{node, u}, -subTreeSum[u]});
                dfs(u);
            }
        }
        if(subTreeSum[node] > 0 && node != 1){
            directions.push_back({{node,parent},subTreeSumn[node]});
        }
    };
    dfs(0,-1);
    cout << directions.size() << endl;
    for(auto i : directions){
        cout << i.first.first << ' ' << i.first.second << ' ' << i.second << endl;
    }
    return 0;
}