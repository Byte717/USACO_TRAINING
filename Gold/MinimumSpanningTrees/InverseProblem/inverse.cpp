#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}
struct DSU{
	#define all(x) begin(x),end(x)
	vector<int> parent, size;
    DSU(int n){parent = vector<int>(n);size = vector<int>(n,1);iota(all(parent),0);}

	int get(int x){while(x != parent[x]) x = parent[x]; return x;}

	bool same_set(int a, int b){return get(a) == get(b);}

	int sz(int x){return size[x];}

	bool link(int a, int b){
		a = get(a), b = get(b);
		if(a == b) return false;
		if(size[a] < size[b]) swap(a,b);
		size[a] += size[b];
		parent[b] = a;
		return true;
	}

};


struct Edge{
    int dist;
    int a, b;
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("inverse.in","r",stdin);
    int n; cin >> n;
    vector<vector<int>> dist(n+1,vector<int>(n+1));
    vector<Edge> edges;
    bool ans = true;
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= n;j++){
            cin >> dist[i][j];
            if(i != j){
                if(j < i && dist[i][j] != dist[j][i]) ans = false;
                if(i < j) edges.push_back(Edge{dist[i][j], i,j});
            }else{
                if(dist[i][j] != 0) ans = false;
            }
        }
    }
    vector<vector<pair<int,int>>> adj(n+1);
    sort(all(edges),[](const Edge &e1, const Edge&e2){return e1.dist < e2.dist;});
    DSU dsu(n+1);
    int total = 0;
    for(auto &[dist, a,b] : edges){
        if(total == n) break;
        if(dsu.link(a,b)){
            total = max(total, dsu.sz(a));
            adj[a].push_back({b,dist});
            adj[b].push_back({a,dist});
        }
    }
    function<bool(int,int,int,int)> dfs = [&](int node, int parent, int src, int distance){
        if(dist[src][node] != distance || (src != node && dist[src][node] != 0)) return false;
        bool ans = true;
        for(auto &i : adj[node]){
            if(i.first == parent) continue;
            ans &= dfs(i.first, node, src, distance + i.second);
        }
        return ans;
    };
    for(int i = 1; i <= n;i++){
        ans &= dfs(i,0,i,0);
    }
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}