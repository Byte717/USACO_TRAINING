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

ll dis(ll x1, ll y1, ll x2, ll y2) {
    return 1ll * (x2 - x1) * (x2 - x1) + 1ll * (y2 - y1) * (y2 - y1);
}

void solve(){
    int n; cin >> n;
    vector<pair<ll,ll>> cords(n);
    for(auto &[x,y] : cords){
        cin >> x >> y;
    }
    ll xs, ys, xt,yt; cin >> xs >> ys >> xt >> yt;
    ll straight = dis(xs,ys, xt,yt);
    bool works = 1;
    for(auto &[x,y] : cords){
        if(dis(x,y,xt,yt) <= straight){
            works = 0;
            break;
        }
    }
    if(works){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}