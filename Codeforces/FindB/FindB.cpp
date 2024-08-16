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
    int n, q; cin >> n >> q;
    vector<ll> c(n);
    vector<ll> pref(n+1), cnt(n+1);
    for(int i = 0; i < n;i++){
        cin >> c[i];
        pref[i+1] = pref[i] + c[i];
        cnt[i+1] = cnt[i] + (c[i] == 1);
    }
    while(q--){
        int l, r; cin >> l >> r;
        l--;
        ll curCnt = cnt[r] - cnt[l];
        ll sum = pref[r] - pref[l];
        if((r-l) + curCnt <= sum && r-l > 1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
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