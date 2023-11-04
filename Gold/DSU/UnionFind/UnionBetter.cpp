#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }//  get parent node

	bool same_set(int a, int b) { return get(a) == get(b); } // if same set

	int size(int x) { return -e[get(x)]; } // size of set

	bool unite(int x, int y) { // put into same group
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("union.in","r",stdin);
    int n, q; cin >> n >> q;
    DSU graph(n);
    for(int i = 0; i < q;i++){
        int t, u , v; cin >> t >> u >> v; 
        if(t == 1){
            if(graph.same_set(u,v)) cout << 1 << endl;
            else cout << 0 << endl;
        }else{
            graph.unite(u,v);
        }
    }
    return 0;
}