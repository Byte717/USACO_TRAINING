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
    vector<int> a(n), b(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    for(int i = 0; i < n;i++){
        cin >> b[i];
    }

    vector<int> ord(n);
    iota(all(ord),0);
    sort(all(ord), [&](int i,int j){
        a[i] + b[i] > a[j] + b[j];
    });
    ll ans = 0;
    for(int i = 0; i < n;i++){
        if(i % 2 == 0){
            ans += a[ord[i]] - 1;
        }else{
            ans -= b[ord[i]] - 1;
        }
    }
    cout << ans << endl;
}




int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}