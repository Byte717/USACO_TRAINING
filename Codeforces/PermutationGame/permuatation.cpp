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
    ll n,k, s1,s2; cin >> n >> k >> s1 >> s2;
    vector<ll> p(n), a(n);
    for(auto&e:p){
        cin>>e;
        e--;
    }
    for(auto&e:a){
        cin>>e;
    }

    auto score = [&](ll start){
        ll i = start, mx = 0;
        ll K = k;
        vector<bool> vis(n);
        ll sum = 0;
        while(!vis[i] && K > 0){
            vis[i] = 1;
            mx = max(mx, sum + (K*a[i]));
            sum += a[i];
            K--;
            i = p[i];
        }
        return mx;
    };
    ll Bodya = score(s1-1), Sasha = score(s2-1);
    if(Bodya == Sasha){
        cout << "Draw" << endl;
        return;
    }

    if(Bodya > Sasha){
        cout << "Bodya" << endl;
    }else{
        cout << "Sasha" << endl;
    }

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