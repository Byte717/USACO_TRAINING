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
    freopen("cons.in","r",stdin);
    int n, m; cin >> n >> m; 
    DSU graph(n);
    int lastNum = n;
    for(int i = 0; i < m;i++){
        int a, b; cin >> a >> b;
        if(!graph.same_set(a,b)){
            lastNum--;
        }
        graph.unite(a,b);
        int largest = 1;
        for(int j = 0; j < n;j++){
            largest = max(largest, graph.size(j));
        }
        cout << lastNum << " " << largest << endl;
    }  
    return 0;
}