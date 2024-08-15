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

double logWithBase(double base, double x) {
    return log(x) / log(base);
}

void solve(){
    ll x, y, k; cin >> x >> y >> k;
    while (k > 0 && x != 1){
        ll distToNearestMult = (x/y+1) * y - x;
        distToNearestMult = max(distToNearestMult, 1LL);
        distToNearestMult = min(k, distToNearestMult);
        x += distToNearestMult;
        while(x % y == 0){
            x /= y;
        }
        k -= distToNearestMult;
    }
    cout << x + (k % (y-1)) << endl; // why?, because we have some operations left over after getting to 1, and that means y-1 repetitions
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