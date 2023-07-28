#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<bool> on_stack;
vector<int> cycle;
bool dfs(int n) {
	visited[n] = on_stack[n] = true;
	for (int u : adj[n]) {
		if (on_stack[u]) {
			cycle.push_back(n);  // start cycle
			on_stack[n] = on_stack[u] = false;
			return true;
		} else if (!visited[u]) {
			if (dfs(u)) {  // continue cycle
				if (on_stack[n]) {
					cycle.push_back(n);
					on_stack[n] = false;
					return true;
				} else {  // found u again
					cycle.push_back(n);
					return false;
				}
			}
			if (!cycle.empty())  // finished with cycle
				return false;
		}
	}
	on_stack[n] = false;
	return false;
}
void solve(){
    int n, m; cin >> n >> m;
    adj = vector<vector<int>>(n);
    on_stack = vector<bool>(n,false);
    visited = vector<bool>(n);
    set<pair<int,int>> redundant;
    for(int i = 0; i < m;i++){
        int a, b; ll c; cin >> a >> b >> c;
        if(redundant.find(make_pair(a,b)) != redundant.end()){
            cout << "NO" << endl;
            return;
        }
        redundant.insert(make_pair(a,b));
        adj[--a].push_back(--b);
    }
    for(int i = 0; i < n;i++){
        if(!visited[i]){
            bool res = dfs(i);
            if(res){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;

}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("third.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}