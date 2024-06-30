#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#ifndef debug
    #pragma GCC optimize("O3","unroll-loops")
    #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#endif

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

struct Weapon{
    int a, b;
    int id;
};

void solve(){
    int n, m; cin >> n >> m;
    vector<Weapon> types(n);
    for(int i = 0; i < n;i++){
        cin >> types[i].a;
    }
    for(int i = 0; i < n;i++){
        cin >> types[i].b;
        types[i].id = i;
    }
    int A = -1;
    for(int i = 0; i < n;i++){
        A = max(A, types[i].a);
    }
    A++;
    vector<int> best(A, MOD), dp(A, 0);
    for(int i = 0; i < n;i++){
        best[types[i].a] = min(types[i].a - types[i].b, best[types[i].a]);
    }
    for(int i = 1; i < A;i++){
        best[i] = min(best[i], best[i-1]);
    }
    for(int i = 1; i < A;i++){
        if(i >= best[i]) dp[i] = 2 + dp[i-best[i]];
    }

    ll ans = 0;
    for(int i = 0; i < m;i++){
        int x; cin >> x;
        if(x >= A){
            int k = (x-A+1+best[A-1])/best[A-1];
            ans += 2*k;
            x -= k*best[A-1];
        }
        ans += dp[x];
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("smithing.in","r",stdin);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}