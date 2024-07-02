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
    int n,k; cin >> n >> k;
    vector<ll> years(n);
    for(int i = 0; i < n;i++){
        cin >> years[i];
    }
    // strat: skip the k biggest gaps
    years.push_back(0);
    sort(all(years));
    vector<pair<ll,pair<ll,ll>>> gaps;
    for(int i = 0; i < n;i++){
        gaps.push_back({years[i+1] - years[i], {years[i], years[i+1]}});
    }
    sort(rall(gaps));
    ll ans = 0;
    for(int i = 0; i < gaps.size();i++){
        if(i < k-1)continue;
        ans += 12;
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("cowYear.in","r",stdin);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}