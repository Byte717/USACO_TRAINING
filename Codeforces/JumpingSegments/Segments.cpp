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
    vector<pair<ll,ll>> seg(n);
    for(int i = 0; i < n;i++){
        cin >> seg[i].first >> seg[i].second;
    }

    auto works = [&](ll k){
        ll lowest = 0, highest = 0;
        for(auto &[L, R] : seg){
            lowest = max(lowest-k, L);
            highest = min(highest+k, R);
            if(lowest > highest) return false;
        }
        return true;
    };

    ll low = -1, high = 1e9;
    while(high - low > 1){
        ll mid = low + (high-low)/2;
        if(works(mid)){
            high = mid;
        }else{
            low = mid;
        }
    }
    cout << high << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    #ifdef LOCAL
	auto _clock_start = chrono::high_resolution_clock::now();
    #endif 
    int t = 1; cin >> t;
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