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


int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

void solve(){
    ll x,y, z, k; cin >> x >> y >> z >> k;
    ll ans = 0;
    for(int a = 1; a <= x; a++){
        for(int b = 1; b <= y;b++){
            if(k %(a*b) != 0) continue;
            ll c = k/(a*b);
            if(c > z) continue;
            ll ways = (x-a+1) * (y-b+1)*(z-c+1);
            ans = max(ans, ways); 
        }
    }
    cout << ans << endl;
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