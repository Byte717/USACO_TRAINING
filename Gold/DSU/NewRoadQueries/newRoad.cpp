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
solution: if each edge has a weight, then it represents the day it was added
so we make a minimum spanning tree using dsu. Now we don't need to sort the edges, as they are sorted by day
then to query each thing, we can use binary ju,ping to find the maximum edge. 

What I learned New Road queries:
     - you can use tree algorithms 
     

*/

const int MAXN = 2e5;
const int LOGN = 18;

struct Dsu{
	vector<int> parent, size;
    Dsu(int n){parent = vector<int>(n);size = vector<int>(n,1);iota(all(parent),0);}

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
int N, M, Q;
vector<pair<int, int>> G[MAXN];
Dsu unionFind(MAXN);

namespace LCA {
int dep[MAXN], par[MAXN][LOGN], val[MAXN][LOGN];

void dfs_init(int u, int p, int d) {
	dep[u] = d;
	par[u][0] = p;
	for (auto [v, w] : G[u])
		if (p != v) {
			val[v][0] = w;
			dfs_init(v, u, d + 1);
		}
}

void init() {
	memset(dep, -1, sizeof(dep));
	memset(par, 0, sizeof(par));
	memset(val, 0, sizeof(val));

	for (int i = 1; i <= N; i++)
		if (dep[i] == -1) dfs_init(i, i, 0);
	for (int k = 1; k < LOGN; k++)
		for (int i = 1; i <= N; i++) {
			par[i][k] = par[par[i][k - 1]][k - 1];
			val[i][k] = max(val[i][k - 1], val[par[i][k - 1]][k - 1]);
		}
}

int query(int a, int b) {
	if (dep[a] > dep[b]) swap(a, b);

	// gets a and b to the same depth
	int ans = 0;
	for (int d = LOGN - 1; d >= 0; d--)
		if (dep[b] - (1 << d) >= dep[a]) {
			ans = max(ans, val[b][d]);
			b = par[b][d];
		}

	assert(dep[a] == dep[b]);

	if (a == b) return ans;

	for (int d = LOGN - 1; d >= 0; d--)
		if (par[a][d] != par[b][d]) {
			ans = max(ans, val[a][d]);
			a = par[a][d];
			ans = max(ans, val[b][d]);
			b = par[b][d];
		}
	if (par[a][0] != par[b][0]) return -1;
	ans = max(ans, val[a][0]);
	ans = max(ans, val[b][0]);

	return ans;
}
}  // namespace LCA
int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("newroad.in","r",stdin);
    cin >> N >> M >> Q;
    for(int i = 1; i <= M;i++){
        int u, v; cin >> u >> v;
        if(unionFind.link(u,v)){
            G[u].emplace_back(v,i);
            G[v].emplace_back(u,i);
        }
    }
    LCA::init();
    while(Q--){
        int a, b; cin >> a >> b;
        cout << LCA::query(a,b) << endl;
    }
    return 0;
}