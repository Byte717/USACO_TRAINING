#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

void solve(){
    int n; cin >> n;
    vector<set<int>> adj(n);
    for(int i = 0; i < n;i++){
        int x; cin >> x;
        x--;
        adj[x].insert(i);
        adj[i].insert(x);
    }
    vector<int> degree(n);
    for(int i = 0; i < n;i++){
        degree[i] = adj[i].size();
    }
    int cycles = 0, noCycles = 0;
    vector<bool> visited(n);
    for(int i = 0; i < n;i++){
        if(!visited[i]){
            queue<int> q;
            vector<int> component;
            component.push_back(i);
            visited[i] = true;
            q.push(i);
            while(!q.empty()){
                int front = q.front(); q.pop();
                visited[front] = true;
                for(int u : adj[front]){
                    if(!visited[u]){
                        q.push(u);
                        component.push_back(u);
                    }
                }
            }
            bool bamboo = false;
            for(int &node : component){
                if(degree[node] == 1) bamboo = true;
            }
            if(bamboo){
                noCycles++;
            }else{
                cycles++;
            }
        }
    }
    cout << cycles + min(noCycles,1) << ' ' << cycles + noCycles << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("round.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}