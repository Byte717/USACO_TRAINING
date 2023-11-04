#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

// #define debug

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

ll gcd(ll x, ll y){
    if(y == 0) return x;
    return gcd(y, x%y); 
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef debug
        freopen("","r",stdin);
    #endif
    int n; cin >> n;
    ll ans = 1;
    ll n2 = max(1,n-100);
    for(ll x = n2; x <= n;x++){
        for(ll y = x;y <= n;y++){
            ll u = x/(gcd(x,y)) * y;
            for(ll z = y; z <= n;z++){
                ll v = u/(gcd(u,z)) * z;
                if(v > ans) ans = v;
            }
        }
    }
    cout << ans << endl;
    return 0;
}