#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define ROF(i,a,b) for(int i = (a); i >= (b); --i)
#define trav(a,x) for(auto& a: x)

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n), rg(n);
	FOR(i,0,m){
		int u, v; cin >> u >> v;
		--u; --v;
		g[u].pb(v);
		rg[v].pb(u);
	}
	FOR(i,0,n-1) g[i].pb(i+1);
	vector<int> dist(n, -1);
	queue<int> q;
	dist[0] = 0;
	q.push(0);
	while(!q.empty()){
		int f = q.front();
		q.pop();
		trav(i, g[f]){
			if(dist[i] == -1){
				dist[i] = dist[f] + 1;
				q.push(i);
			}
		}
	}
	multiset<int> max_good_rights;
	vector<vector<int>> to_erase(n);
	string ans = string(n - 1, '0');
	ROF(i,n-1,0){
		trav(j, rg[i]){
			int max_right = i - dist[j];
			max_good_rights.insert(max_right);
			to_erase[j].pb(max_right);
		}
		trav(j, to_erase[i]){
			max_good_rights.erase(max_good_rights.find(j));
		}
		if(i < n - 1){
			int max_good_right = max_good_rights.empty() ? -1 : *prev(max_good_rights.end());
			if(i >= max_good_right - 1){
				ans[i] = '1';
			}
		}
	}
	cout << ans << endl;
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	cin >> t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}