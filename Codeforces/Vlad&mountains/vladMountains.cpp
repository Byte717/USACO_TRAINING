#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

struct dsu{
	#define all(x) begin(x),end(x)
	vector<int> parent, size;
    dsu(int n){parent = vector<int>(n);size = vector<int>(n,1);iota(all(parent),0);}

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

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}
struct edge{
    /* data */
    int a, int b;
    ll energy;
    bool operator<(const edge&p2){
        return energy < p2.energy;
    }
};


void solve(){
    int n,m; cin >> n >> m;
    vector<ll> heights(n);
    for(int i = 0;i < n;i++){
        cin >> heights[i];
    }
    vector<edge> edges;
    for(int i = 0; i < m;i++){
        int a, b; cin >> a >> b;
        a--; b--;
        edges.push_back({a,b,heights[a]-heights[b]});
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}