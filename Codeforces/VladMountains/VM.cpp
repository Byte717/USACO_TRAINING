#include <bits/stdc++.h>

#define x first
#define y second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

typedef long double ld;
typedef long long ll;

using namespace std;

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

    bool reachable(int a, int b){
        return get(a) == get(b);
    }
};

void solve(int tc) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> h(n);
    for(auto &e: h) cin >> e.x;
    for(int i = 0; i < n; ++i){
        h[i].y = i;
    }
    dsu graph(n);
    vector<vector<int>> sl(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        if(h[u].x > h[v].x) sl[u].emplace_back(v);
        else sl[v].emplace_back(u);
    }
    int q;
    cin >> q;
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
        ans[e.x.y] = graph.reachable(e.y.x, e.y.y);
    }
    for(bool e: ans) cout << (e? "YES": "NO") << "\n";
}

bool multi = true;

signed main() {
    freopen("vlad.in","r",stdin);
    int t = 1;
    if(multi) cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
        if(i < t) cout << "\n";
    }
    return 0;
}