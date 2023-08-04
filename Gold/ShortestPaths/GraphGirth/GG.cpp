#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("GG.in","r",stdin);
    int n, m; cin >> n >> m;
    vector<vector<int>>adj(n);
    for(int i = 0; i < m;i++){
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    auto bfs = [&](int start){
        int ans = INF;
        vector<int> dist(n, -1);
        dist[start] = 0;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int node = q.front(); q.pop();
            for(int &i : adj[node]){
                if(dist[i] == -1){
                    dist[i] = dist[node] + 1;
                    q.push(i);
                }else if(dist[i] >= dist[node]){
                    ans = min(ans, 1 + dist[node] + dist[i]);
                }
            }
        }
        return ans;
    };

    int ans = 1e6;
    for(int i = 0; i < n;i++){
        int res = bfs(i);
        ans = min(ans,res);
    }
    cout << ans << endl;
    return 0;
}