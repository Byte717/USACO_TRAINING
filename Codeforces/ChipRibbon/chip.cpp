#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


void solve(){
    int n; cin >> n;
    if(n == 1){
        ll x; cin >> x;
        cout << x-1 << endl;
        return;
    }
    vector<int> c(n);
    for(int i = 0; i < n;i++){
        cin >> c[i];
    }
    ll res = 0;
    for(int i = 1; i < n;i++){
        if(c[i] > c[i-1]){
            res += c[i] - c[i-1];
        }
    }
    cout << res +(c[0] -1) << endl;    
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}