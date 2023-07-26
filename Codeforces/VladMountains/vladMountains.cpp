#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()
#define x first
#define y second

typedef long long ll;

using namespace std;

struct Query{
    int a, b;
    ll energy;
    int idx;
    bool operator<(Query &q2){
        if(energy == q2.energy) return idx < q2.idx;
        return energy < q2.energy;
    }
};

struct dsu{
    vector<int> p, lvl;

    dsu(int n){
        p.resize(n);
        lvl.assign(n, 0);
        iota(all(p), 0);
    }

    int get(int i){
        if(i == p[i]) return i;
        return p[i] = get(p[i]);
    }

    bool unite(int a, int b){
        a = get(a);
        b = get(b);
        if(a == b){
            return false;
        }
        if(lvl[a] < lvl[b])swap(a, b);
        p[b] = a;
        if(lvl[a] == lvl[b]){
            ++lvl[a];
        }
        return true;
    }

    bool same_set(int a, int b){
        return get(a) == get(b);
    }
};




void solve(){
    int n,m; cin >> n >> m;
    vector<pair<int,int>> h(n);
    for(int i = 0; i < n;i++){
        cin >> h[i].first;
        h[i].second = i;
    }
    vector<vector<int>> sl(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        if(h[u].x > h[v].x) sl[u].emplace_back(v);
        else sl[v].emplace_back(u);
    }
    dsu graph(n);
    int q; cin >> q;
    vector<pair<pair<int, int>, pair<int, int>>> req(q);
    for(auto &e: req){
        cin >> e.y.x >> e.y.y >> e.x.x;
        --e.y.x, --e.y.y;
        e.x.x += h[e.y.x].x;
    }
    for(int i = 0; i < q; ++i){
        req[i].x.y = i;
    }

    sort(all(h));
    sort(all(req));
    vector<bool> ans(q);
    int j = 0;
    for(auto e: req){
        while (j < n && h[j].x <= e.x.x) {
            for(int u: sl[h[j].y]){
                graph.unite(h[j].y, u);
            }
            ++j;
        }
        ans[e.x.y] = graph.same_set(e.y.x, e.y.y);
    }
    for(bool e : ans) cout << (e ?"YES":"NO") << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("vlad.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
        if(t != 0){cout << endl;}
    }
    return 0;
}