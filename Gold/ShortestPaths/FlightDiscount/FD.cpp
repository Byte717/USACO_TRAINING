#include <bits/stdc++.h>
#define ll long long 
#define INF 1e5

using namespace std; 





int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("FD.in","r",stdin);
    int n,m; cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n);
    vector<vector<pair<int,int>>> radj(n);

    for(int i = 0; i < m;i++){
        int a, b,c; cin >> a >> b >> c;
        adj[a-1].push_back({b-1,c});
        radj[b-1].push_back({a-1,c});
    }

    auto min_cost = [&](int start, vector<vector<pair<int,int>>> graph){
        vector<ll> dists(n, INF);
        dists[start] = 0;
        priority_queue<pair<ll,int>> frontier;
        frontier.push({0,start});
        while(!frontier.empty()){
            auto currentState = frontier.top();
            frontier.pop();
            int curr = currentState.second;
            if(-currentState.first != dists[curr]) {continue;}

            for(auto [n,nc] : graph[curr]){
                ll newCost = dists[curr] + nc;
                if(newCost < dists[n]){
                     dists[n] = newCost;
                     frontier.push({-newCost,n});
                }
            }
        }
        return dists;
    };
    auto startCost = min_cost(0,adj);
    auto endCost = min_cost(n-1,radj);
    ll totalMin = INF;
    for(int i = 0; i < n;i++){
        for(auto [n,nc] : adj[i]){
            if(startCost[i] == INF || endCost[i] == INF){
                continue;
            }
            totalMin = min(totalMin, startCost[i] + (nc/2) + endCost[i]);
        }
    }
    cout << totalMin << endl;
    return 0;
}