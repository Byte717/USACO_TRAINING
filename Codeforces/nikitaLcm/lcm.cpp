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


int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

inline ll lcm(ll a, ll b){return a*b/__gcd(a,b);}

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    unordered_set<ll> s;
    for(int i = 0; i < n;i++){
        cin >> a[i];
        s.insert(a[i]);
    }
    vector<pair<ll,ll>> dp(n, {1, -1});
    dp[0].second = a[0];
    for(int i = 1; i < n;i++){
        dp[i].second = a[i];
        for(int j = 0; j < i;j++){
            if(s.find(lcm(dp[j].second, a[i])) == s.end() && dp[j].first+1 > dp[i].first){
                dp[i] = {dp[j].first + 1, lcm(dp[j].second, a[i])};
            }
        }
    }
    ll mx = 0;
    for(int i = 0; i < n;i++){
        mx = max(mx, dp[i].first);
    }
    cout << mx << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("lcm.in","r",stdin);
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}