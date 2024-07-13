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



void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    ll pref_max = 0, s = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        pref_max = max(pref_max, (ll) a[i]);
        
        ll d = pref_max - a[i];
        s += d;
        mx = max(mx, d);
    }
    
    cout << s + mx << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("kSort.in","r",stdin);
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}