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


void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    if(n == 1 && a[0] == 0){
        cout << 1 << endl;
        return;
    }
    set<ll> elements;
    ll prefSum = 0;
    ll ans = 0;
    for(int i = 0; i < n;i++){
        prefSum += a[i];
        elements.insert(a[i]);
        if(prefSum == 0){
            ans++;
            continue;
        }
        if(prefSum % 2 == 0 && elements.find(prefSum/2) != elements.end()){
            ans++;
        }
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("pref.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}