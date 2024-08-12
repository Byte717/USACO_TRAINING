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
    for(auto &x : a) cin >> x;
    // dp[i] = weight if ends at i = dp[i-1] + (number of indices such that a[i] is there previously)
    map<ll,ll> cnt;
    vector<ll> dp(n+1,0);
    ll ans = 0;
    for(ll i = 1; i <= n;i++){
        dp[i] = dp[i-1] + (cnt.count(a[i-1]) ? cnt[a[i-1]] : 0);
        cnt[a[i-1]]+= i;
        ans+=dp[i];
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("weight.in","r",stdin);
    ll t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}