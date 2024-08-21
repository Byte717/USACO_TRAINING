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

template<typename T> inline bool flipped(T a,int i){return a&(1ll<<i);}


void solve(){
    ll a, b, r; cin >> a >> b >>r;
    ll x = 0;
    bool firstBit = 1;
    if(a > b) swap(a,b);
    for(int i = 59;i >= 0;i--){
        bool bitA = flipped<ll>(a,i);
        bool bitB = flipped<ll>(b,i);
        if(firstBit){
            firstBit = 0;
        }else{
            if(!bitA && x+(1<<i) <= r){
                x += (1<<i);
                a^=(1<<i);
                b ^= (1<<i);
            }
        }
    }
    cout << (b-a) << endl;
}

signed main(){
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