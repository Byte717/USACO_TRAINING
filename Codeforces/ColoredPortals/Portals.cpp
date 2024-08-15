#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// #define debug

#ifndef debug
    #pragma GCC optimize("O3","unroll-loops")
    #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#endif

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

void dfs(int u, int p, vector<vector<int>> memo, vector<int> &lev, int log, vector<vector<int>> g) 
{ 
    memo[u][0] = p; 
    for (int i = 1; i <= log; i++) 
        memo[u][i] = memo[memo[u][i - 1]][i - 1]; 
    for (int v : g[u]) 
    { 
        if (v != p) 
        { 
            lev[v] = lev[u] + 1; 
            dfs(v, u, memo, lev, log, g); 
        } 
    } 
} 
 
// Function to return the LCA of nodes u and v 
int lca(int u, int v, int log, vector<int> &lev, vector<vector<int>> memo) 
{ 
    // The node which is present farthest 
    // from the root node is taken as u 
    // If v is farther from root node 
    // then swap the two 
    if (lev[u] < lev[v]) 
        swap(u, v); 
 
    // Finding the ancestor of u 
    // which is at same level as v 
    for (int i = log; i >= 0; i--) 
        if ((lev[u] - pow(2, i)) >= lev[v]) 
            u = memo[u][i]; 
 
    // If v is the ancestor of u 
    // then v is the LCA of u and v 
    if (u == v) 
        return u; 
 

    for (int i = log; i >= 0; i--) 
    { 
        if (memo[u][i] != memo[v][i]) 
        { 
            u = memo[u][i]; 
            v = memo[v][i]; 
        } 
    } 
 
    return memo[u][0]; 
} 


struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }//  get parent node

	bool same_set(int a, int b) { return get(a) == get(b); } // if same set

	int size(int x) { return -e[get(x)]; } // size of set

	bool link(int x, int y) { // put into same group
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};
int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

void solve(){ // djikstras and store the graph in a map
    int n, q; cin >> n >> q;
    vector<string> cities(n);
    unordered_map<char, vector<int>> graph;
    for(int i = 0; i < n;i++){
        cin >> cities[i];
        graph[cities[i][0]].push_back(i);
        graph[cities[i][1]].push_back(i);
    }
    vector<pair<int,pair<int,int>>> edges;
    for(auto &[x,y] : graph){
        for(int i = 1; i < y.size();i++) edges.push_back({abs(y[i]- y[i-1]), {y[i],y[i-1]}});
    }
    sort(all(edges));
    DSU dsu(n);
    vector<vector<int>> adj(n);
    for(auto &[dist,nodes] : edges){
        auto [x,y] = nodes;
        if(dsu.link(x,y)){
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }
    int lg = LOG2(n) + 1;
    vector<int> lev(n + 1); 
    vector<vector<int>> memo(n+1, vector<int>(lg + 1, -1));
    dfs(0,-1, memo, lev, lg, adj);
    for(int i = 0; i < q;i++){
        int x, y; cin >> x >> y;
        x--;y--;
        cout << lev[x] + lev[y] - (2*lev[lca(x,y,lg,lev, memo)]) << endl;
    }
    // auto shortestPath = [&](int start){
    //     vector<int> dist(n, 1e6);
    //     dist[start] = 0;
    //     priority_queue<pair<int,int>> q;
    //     q.push({0,start});
    //     while(!q.empty()){
    //         auto [d,x] = q.top();
    //         q.pop();
    //         d = -d;
    //         for(auto &i : graph[cities[x][0]]){
    //             if(x != i){
    //                 int w = abs(x-i);
    //                 if(dist[i] > dist[x] + w){
    //                     dist[i] = dist[x]+w;
    //                     q.push({-dist[i], i});
    //                 }
    //             }
    //         }
    //         for(auto &i : graph[cities[x][1]]){
    //             if(x != i){
    //                 int w = abs(x-i);
    //                 if(dist[i] > dist[x] + w){
    //                     dist[i] = dist[x]+w;
    //                     q.push({-dist[i], i});
    //                 }
    //             }
    //         }
    //     }
    //     return dist;
    // };

    // unordered_map<int,vector<int>> dists;
    // for(int i = 0; i < q;i++){
    //     int x, y; cin >> x >> y;
    //     x--;y--;
    //     if(x == y){
    //         cout << 0 << endl;
    //         continue;
    //     }
    //     if(dists.find(x) == dists.end() && dists.find(y) == dists.end()){
    //         dists[x] = shortestPath(x);
    //         dists[y] = shortestPath(y);
    //         cout << (dists[x][y] == 1e6 ? -1 : dists[x][y]) << endl;
    //     }else if(dists.find(x) != dists.end()){
    //         dists[y] = shortestPath(y);
    //         cout << (dists[x][y] == 1e6 ? -1 : dists[x][y]) << endl;
    //     }else if(dists.find(y) != dists.end()){
    //         dists[x] = shortestPath(x);
    //         cout << (dists[y][x] == 1e6 ? -1 : dists[y][x]) << endl;
    //     }
    // }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("portals.in","r",stdin);
    #ifdef LOCAL
	auto _clock_start = chrono::high_resolution_clock::now();
    #endif 
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    #ifdef LOCAL
    cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
        chrono::high_resolution_clock::now()
            - _clock_start).count() << "ms." << endl;
    #endif
    return 0;
}