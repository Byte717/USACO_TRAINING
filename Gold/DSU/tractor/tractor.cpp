#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std; 
const int MAXN = 500;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

    void reset(int N){e = vector<int>(N, -1);}
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


struct Cell{
    int i, j;
};

struct Edge{
    Cell to, from;
    int cost;
};

int n;
bool inBound(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool cmp(Edge &e1, Edge &e2){
    return e1.cost < e2.cost;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("tractor.in","r",stdin);
    cin >> n;
    const int half = (n*n+1)/2;
    int grid[n][n];
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            cin >> grid[i][j];
        }
    }
    vector<Edge> edges;

    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            for(int k = 0; k < 4;k++){
                Cell adj = {i+dirX[k],j+dirY[k]};
                if(inBound(adj.i,adj.j) && grid[i][j] >= grid[adj.i][adj.j]){
                    edges.push_back({adj, {i,j}, grid[i][j]-grid[adj.i][adj.j]});
                }
            }
        }
    }
    DSU dsu(n*n);

    sort(all(edges),cmp);
    for(Edge e : edges){
        dsu.unite(e.from.i*n + e.from.j, e.to.i*n + e.to.j);
        if(dsu.size(e.from.i*n + e.from.j) == half || dsu.size(e.to.i*n + e.to.j) == half){
            cout << e.cost << endl;
            return 0;
        }
    }
    return 0;
}