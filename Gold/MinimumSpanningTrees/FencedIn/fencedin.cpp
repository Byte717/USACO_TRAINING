#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;
/*
solution: each of the sections is a node. adjacent sections are connected with the weight being the fence length in common
then we would make a maximum spanning tree and add the weight of edges you ignored

what I learned Fenced in Gold:(revisit)
    - try to make grid problems into graph problems

*/


const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

struct DSU{
	#define all(x) begin(x),end(x)
	vector<int> parent, size;
    DSU(int n){parent = vector<int>(n);size = vector<int>(n,1);iota(all(parent),0);}

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

struct Edge{
    int weight;
    int a, b;
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("fencedin.in","r",stdin);
    int A,B, n, m; cin >> A >> B >> n >> m;
    vector<int> x(n+1), y(m+1);
    for(int i = 1; i <= n;i++) cin >> x[i];
    for(int i = 1; i <= n;i++) cin >> y[i];
    x.push_back(A); y.push_back(B);
    sort(all(x)); sort(all(y));
    m +=2; n +=2;
    vector<Edge> edges;
    int sector = 0, row = 1;
    while(row < m){
        for(int i = 0; i < n-2;i++){
            edges.push_back(Edge{y[row]-y[row-1], sector, sector+1});
            sector++;
        }
        sector++;
        row++;
    }
    sector = n-1;
    int col = 1;
    while(col < n){
        int init = sector;
        for(int i = 0; i < m-2;i++){
            edges.push_back(Edge{x[col]-x[col-1], sector - (n-1), sector});
            sector+= (n-1);
        }
        sector = init+1;
        col++;
    }
    DSU dsu((n+2)*(m+2));
    sort(all(edges), [](const Edge&e1, const Edge &e2){return e1.weight < e2.weight;});
    ll ans = 0;
    for(Edge &i : edges){
        if(dsu.link(i.a,i.b)) ans += i.weight;
    }
    cout << ans << endl;
    return 0;
}