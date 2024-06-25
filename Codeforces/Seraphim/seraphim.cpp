#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// #pragma GCC optimize("O3","unroll-loops")
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

void solve(){
    int m, n; cin >> n >> m;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    for(int i = 0; i < n;i++){
        cin >> b[i];
    }
    reverse(all(b));
    reverse(all(a));
    ll bSum = 0;
    ll pref = 0;
    for(int i = 0; i < n-m;i++){
        if(a[i]  < b[i]){
            pref += bSum;
            pref += a[i];
            bSum = 0;
        }else{
            bSum+= b[i];
        }
    }
    ll res = INF;
    for(int i = n-m; i < n;i++){
        res = min(res, pref + bSum + a[i]);
        bSum += b[i];
    }

    cout << res << endl;

}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("seraphim.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}