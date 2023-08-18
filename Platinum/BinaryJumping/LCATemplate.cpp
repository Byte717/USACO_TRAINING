vector<pair<int, int>> G[MAXN];
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