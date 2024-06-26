#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// #define debug

#ifndef debug
    #pragma GCC optimize("O3","unroll-loops")
    #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#endif

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


void solve(){
    int x, y; cin >> x >> y;
    int maxSuffix = 0;
    for(int i = 0; i < 32;i++){
        if((!(x&(1<<i)) && !(y&(1<<i))) || ((x&(1<<i)) && (y&(1<<i)))){ // 0 at i'th bit of x and 0 at i'th bit of y
            maxSuffix++;
        }else{
            break;
        }
    }
    cout << (1<<maxSuffix) << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("xor.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}