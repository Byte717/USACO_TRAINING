#include <bits/stdc++.h>

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

int n, half;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
DSU dsu(1);
int globalCost;


void CheckAdjacent(int i, int j){
    if(i > 0){
        if(abs(grid[i-1][j] - grid[i][j]) <= globalCost){
            dsu.unite(i+j, i-1+j);
        }
    }
    if(j > 0){
        if(abs(grid[i][j-1] - grid[i][j]) <= globalCost){
            dsu.unite(i+j, i+j-1);
        }
    }
    if(i < n-1){ // can be n-1
        if(abs(grid[i+1][j] - grid[i][j]) <= globalCost){
            dsu.unite(i+j, i+1+j);
        }
    }
    if(j < n-1){
        if(abs(grid[i][j+1] - grid[i][j]) <= globalCost){
            dsu.unite(i+j, i+j+1);
        }
    }

}

void floodFill(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= n) return;
    if(visited[i][j]) return;

    visited[i][j] = true;
    CheckAdjacent(i,j);

    floodFill(i+1,j);
    floodFill(i,j+1);
    floodFill(i-1,j);
    floodFill(i,j-1);

}


bool works(int mid){
    globalCost = mid;
    dsu.reset(n);
    floodFill(0,0);
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            if(dsu.size(i+j) >= half){
                return true;
            }
        }
    }
    return false;
}



int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("tractor.in","r",stdin);
    cin >> n;
    half = ceil(n*n/2);
    dsu.reset(n*n);
    int lowest = INT32_MAX, highest = INT32_MIN;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            cin >> grid[i][j];
            highest = max(highest,grid[i][j]);
            lowest = min(lowest,grid[i][j]);
        }
    }


    int low = 0, high = highest-lowest +1, mid, ans;
    while(low < high){
        mid = low + (high-low)/2;
        if(works(mid)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid +1;
        }

    }
    cout << ans << endl;
    return 0;
}