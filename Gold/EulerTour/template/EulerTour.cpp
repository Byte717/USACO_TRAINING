#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 

int n;  // The number of nodes in the graph
vector<int> graph[100000];
int timer = 0, tin[100000], euler_tour[200000];
int segtree[800000];  // Segment tree for RMQ

void dfs(int node = 0, int parent = -1) {
	tin[node] = timer;  // The time when we first visit a node
	euler_tour[timer++] = node;
	for (int i : graph[node]) {
		if (i != parent) {
			dfs(i, node);
			euler_tour[timer++] = node;
		}
	}
}

int mn_tin(int x, int y) {
	if (x == -1) return y;
	if (y == -1) return x;
	return (tin[x] < tin[y] ? x : y);
}

// Build the segment tree: run `build()` after running dfs`
void build(int node = 1, int l = 0, int r = timer - 1) {
	if (l == r) segtree[node] = euler_tour[l];
	else {
		int mid = (l + r) / 2;
		build(node * 2, l, mid);
		build(node * 2 + 1, mid + 1, r);
		segtree[node] = mn_tin(segtree[node * 2], segtree[node * 2 + 1]);
	}
}

int query(int a, int b, int node = 1, int l = 0, int r = timer - 1) {
	if (l > b || r < a) return -1;
	if (l >= a && r <= b) return segtree[node];
	int mid = (l + r) / 2;
	return mn_tin(query(a, b, node * 2, l, mid),
	              query(a, b, node * 2 + 1, mid + 1, r));
}

// Make sure you run $dfs` and `build()` before you run this
int lca(int a, int b) {
	if (tin[a] > tin[b]) swap(a, b);
	return query(tin[a], tin[b]);
}