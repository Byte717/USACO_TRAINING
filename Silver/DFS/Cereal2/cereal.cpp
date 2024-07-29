#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

vector<vector<pair<int,int>>> adj;
vector<pair<int,int>> edges;

struct DSU{
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

void dfs(int node,int parent){
    for(auto &[n,cow] : adj[node]){
        if(n != parent){
            cout << cow << endl;
            dfs(n,node);
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int n, m; cin >> n >> m;
    adj = vector<vector<pair<int,int>>>(m);
    edges.resize(n);
    for(int i = 0; i < m;i++){
        int a, b; cin >> a >> b;
        edges[i] = {--a,--b};
    }

    DSU dsu(n);
    int hungry = 0;
    for(int i = 0; i < n;i++){
        if(!dsu.same_set(edges[i].first, edges[i].second)){
            dsu.link(edges[i].first, edges[i].second);
            adj[edges[i].first].push_back({edges[i].second, i});
            adj[edges[i].second].push_back({edges[i].first, i});
        }else{
            hungry++;
        }
    }
    dfs(0, -1);
    return 0;
}