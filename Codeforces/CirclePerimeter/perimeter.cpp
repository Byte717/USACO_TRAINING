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

ll distsq(ll x, ll y){
    return x*x + y*y;
}

void solve(){
    ll r; cin >> r;
    ll y = r;
    ll ans = 0;
    for(ll x = 0; x <= r;x++){
        while(distsq(x, y) >= (r+1)*(r+1)){ // use "two pointers" to find max y
            y--;
        }
        ll thresh = y;
        while(distsq(x,thresh)  >= r*r && thresh > 0){ // then try all y with everything less than the max possible
            thresh--;
            ans++;
        }
    }
    cout << ans*4 << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    #ifdef LOCAL
	auto _clock_start = chrono::high_resolution_clock::now();
    #endif 
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    #ifdef LOCAL
    cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
        chrono::high_resolution_clock::now()
            - _clock_start).count() << "ms." << endl;
    #endif
    return 0;
}