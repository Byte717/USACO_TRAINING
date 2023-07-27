#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;
struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }//  get parent node

	bool same_set(int a, int b) { return get(a) == get(b); } // if same set

	int size(int x) { return -e[get(x)]; } // size of set

	bool link(int x, int y) { // put into same group
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};




struct Rel{
    Rel(ll x,ll y,ll z){
        p = x; q = y; r = z;
    }
    ll p,q;
    ll r;

    bool operator<(const Rel&r2){
        return r < r2.r;
    }
};

struct Query{
    ll k;
    ll v;
    ll idx;
    Query(ll x,ll y,ll z){
        k = x; v = y; idx = z;
    }
    bool operator<(const Query&q2){
        return k < q2.k;
    }
};


vector<Rel> adj;
vector<Query> queries;
ll n, q;


void solve(){
    sort(rall(queries));
    sort(rall(adj));
    DSU graph(n);
    vector<ll> ans(q,0);
    ll idx = 0;
    for(auto &q : queries){
        ll v = q.v;
        ll k = q.k;
        while(idx < n && adj[idx].r >= k){
            graph.link(adj[idx].p, adj[idx].q);
            idx++;
        }
        ans[q.idx] = graph.size(v)-1;
    }
    for(auto i : ans) cout << i << endl;
}



int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("mootube.in","r",stdin);
    cin >> n >> q;
    for(ll i = 0; i < n-1;i++){
        ll pi,qi; ll ri; cin >> pi >> qi >> ri;
        pi--;qi--;

        adj.push_back(Rel(pi,qi,ri));
    }
    for(ll i = 0; i < q;i++){
        ll k; ll v; cin >> k >> v;
        v--;
        queries.push_back(Query(k,v,i));
    }
    solve();
    return 0;
}