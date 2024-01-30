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
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);

    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    for(int i = 0; i < m;i++){
        cin >> b[i];
    }

    // if(n == m){
    // sort(all(a));
    // sort(all(b));
    // reverse(all(b));
    // ll d = 0;
    // for(int i = 0; i < n;i++){
    //     d += abs(a[i] - b[i]);
    // }
    // cout << d << endl;
    // return;
    // }

    multiset<ll> options(b.begin(),b.end());
    sort(all(a));
    ll d = 0;
    for(int i = 0; i < n;i++){
        auto top = prev(options.end());
        auto bottom = options.begin();
        if(abs(*top - a[i]) > abs(*bottom - a[i])){
            d += abs(*top - a[i]);
            options.erase(top);
        }else{
            d += abs(*bottom - a[i]);
            options.erase(bottom);
        }
    }
    cout << d << endl;

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("array.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}