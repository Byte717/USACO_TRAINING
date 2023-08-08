#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

/*
each connected componenet can be a cycle
for maximum cycles

for minimum, its the number of cycles - the number that does have a loop


*/

struct component{
    bool hasCycle;
    // vector<int> nodes;
};


void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n;i++){
        int x; cin >> x;
        x--;
        // adj[x].push_back(i);
        adj[i].push_back(x);
    }
    vector<bool> visited(n,false), onStack(n,false);
    // vector<int> cycle;
    function<bool(int)> dfs = [&](int node){
        visited[node] = onStack[node] = true;
        for(int u : adj[node]){
            if(onStack[u]){
                // cycle.push_back(u);
                onStack[node] = onStack[u] = false;
                return true;
            }else if(!visited[u]){
                if(dfs(u)){
                    // cycle.push_back(node);
                    onStack[node] = false;
                    return true;
                }else{
                    // cycle.push_back(node);
                    return false;
                }
                // if(!cycle.empty()){
                //     return false;
                // }
            }
        }
        onStack[node] = false;
        return false;
    };
    vector<component> conComps;
    for(int i = 0; i < n;i++){
        if(!visited[i]){
            fill(all(onStack),false);
            // cycle.clear();
            bool res = dfs(i);
            conComps.push_back({res});
        }
    }
    int MXCycles = conComps.size();
    int MNCycles = 1;
    int numCyclesAlready = 0;
    for(auto &i : conComps){
        if(i.hasCycle){
            numCyclesAlready++;
        }
    }
    MNCycles = conComps.size() - numCyclesAlready;
    if(numCyclesAlready == 0){
        MNCycles = 1;
    }
    cout << MNCycles << ' ' << MXCycles << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("round.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}