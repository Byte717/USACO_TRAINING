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


struct Cell{
    int i, j;
    int height;
};

bool cmp(Cell &c1, Cell &c2){
    return c1.height < c2.height;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n, m; cin >> n >> m;
    int grid[n][m];
    vector<Cell> mountains;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            cin >> grid[i][j];
            mountains.push_back({i,j,grid[i][j]});
        }
    }
    sort(rall(mountains),cmp);
    DSU dsu(n*m);
    return 0;
}