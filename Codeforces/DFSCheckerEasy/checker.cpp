#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define debug

#ifndef debug
    #pragma GCC optimize("O3","unroll-loops")
    #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#endif

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define maxn 500005

int read() {
    int x = 0, w = 0; char ch = getchar();
    while(!isdigit(ch)) w |= ch == '-', ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return w ? -x : x;
}
int n, Q, fa[maxn], p[maxn], q[maxn], siz[maxn];
set<int> son[maxn];
int chk(int x) {
    return son[x].empty() ? 1 : (q[x] < *son[x].begin() && *--son[x].end() + siz[p[*--son[x].end()]] <= q[x] + siz[x]);
}
void solve() {
    n = read(), Q = read();
    ru(i, 1, n) siz[i] = 1, son[i].clear();
    ru(i, 2, n) fa[i] = read();
    rd(i, n, 2) siz[fa[i]] += siz[i];
    ru(i, 1, n) son[fa[p[i] = read()]].insert(i), q[p[i]] = i;
    int cnt = 0;
    ru(i, 1, n) cnt += chk(i);
    while(Q--) {
        int i = read(), j = read(), x = p[i], y = p[j];
        set<int> s; s.insert(x), s.insert(y), s.insert(fa[x]), s.insert(fa[y]);
        for (auto x: s) if(x) cnt -= chk(x);
        son[fa[x]].erase(i), son[fa[y]].erase(j);
        swap(p[i], p[j]), swap(q[x], q[y]);
        son[fa[x]].insert(j), son[fa[y]].insert(i);
        for (auto x: s) if(x) cnt += chk(x);
        puts(cnt == n ? "YES" : "NO");
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}