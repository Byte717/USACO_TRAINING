#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
vector<vector<int>> graph;
vector<bool> vis;
struct Edge{
    int a,b;
    ll w;
};

void dfs(int node){
    if(vis[node]){
        return;
    }
    vis[node] = true;
    for(int & i : graph[node]){
        dfs(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("wormsort.in","r",stdin);
    freopen("wormsort.out","w",stdout);
    int n, m; cin >> n >> m; 
    vector<int> cows(n);
    vis.resize(n);
    graph.resize(n);
    for(auto& i : cows){
        cin >> i;
        i--;
    }
    if(is_sorted(all(cows))){
        cout << -1 << endl;
        return 0;
    }
    int a, b;ll w;
    ll maxWidth = -1;
    vector<Edge> edges;
    for(int i = 0; i < n;i++){
        cin >> a >> b >> w;
        edges.push_back(Edge{--a,--b,w});
        maxWidth = max(maxWidth, w);
    }

    ll low = 0, hi = maxWidth, mid;
    ll ans = -1;
    while(low <= hi){
        mid = low + (hi - low)/2;

        // graph = vector<vector<int>>(n);
        for(int i = 0; i < m;i++){
            if(edges[i].w >= mid){
                graph[edges[i].a].push_back(edges[i].b);
                graph[edges[i].b].push_back(edges[i].a);
            }
        }
        fill(all(vis), false);

        for(int i = 0; i < n;i++){
            if(!vis[i]){
                dfs(i);
            }
        }
        bool works = true;
        for(int i = 0; i < n;i++){
            if(cows[i] == i+1){
                continue;
            }else{
                if(!vis[i]){
                    works = false;
                }
            }
        }

        if(works){
            ans = mid;
            low = mid + 1;
        }else{
            hi = mid - 1;
        }
    }

    cout << ans-1 << endl;
    return 0;
}