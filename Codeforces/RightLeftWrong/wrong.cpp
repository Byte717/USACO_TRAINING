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
    ll n; cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n;i++){
        cin >> a[i];
    }
    vector<ll> pref(n+1);
    for(ll i = 0; i < n;i++){
        pref[i+1] = pref[i] + a[i];
    }
    string s; cin >> s;
    ll ans = 0;
    ll l = 0, r = n-1;
    while(r > l){
        while(l < n && s[l] == 'R'){
            l++;
        }
        while(r>= 0 && s[r] == 'L'){
            r--;
        }// find the smallest subsegment and take the largest one as well
        if(l < r){
            ans += pref[r+1] - pref[l]; 
            l++;
            r--;
        }
    }
    cout << ans << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    #ifdef LOCAL
	auto _clock_start = chrono::high_resolution_clock::now();
    #endif 
    ll t = 1; cin >> t;
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