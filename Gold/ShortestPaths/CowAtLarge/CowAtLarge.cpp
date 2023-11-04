#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

/*
solution: find mindist from leaves and min dist from k. then start a bfs or dfs from k. for whatever node has bessie ariving after the farmers, ans++;

what I learned Cow at large:
    - you can start bfs from multiple places

*/

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("large.in","r",stdin);
    ll n, k; cin >> n >> k;
    k--;
    vector<vector<ll>> adj(n);
    for(int i = 0; i < n-1;i++){
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    vector<ll> bessieDist(n,INF);
    bessieDist[k] = 0;
    queue<ll> q;
    q.push(k);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(auto & node : adj[top]){
            if(bessieDist[top] + 1 < bessieDist[node]){
                bessieDist[node] = bessieDist[top] + 1;
                q.push(node);
            }
        }
    }
    vector<ll> exitDist(n,INF);
    for(int i = 0; i < n;i++){
        if(adj[i].size() == 1){
            q.push(i);
            exitDist[i] = 0;
        }
    }
    while(!q.empty()){
        int top = q.front(); q.pop();
        for(auto & node : adj[top]){
            if(exitDist[top] + 1 < exitDist[node]){
                exitDist[node] = exitDist[top] + 1;
                q.push(node);
            }
        }
    }
    ll ans = 0;
    q.push(k);
    vector<bool> vis(n);
    while(!q.empty()){
        ll top = q.front();
        q.pop();
        if(bessieDist[top] >= exitDist[top]){
            ans++;
            continue;
        }

        if(vis[top]){
            continue;
        }
        vis[top] = true;
        for(auto & i : adj[top]) q.push(i);
    }
    cout << ans << endl;
    return 0;
}