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

template<typename T> inline bool flipped(T a,int i){return a&(1ll<<i);}
template<typename T> inline T pow2(int exp){return (1ll << exp);}

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    ll low = 0, high = (1e9)*n;
    while (low < high){
        ll mid = low + (high-low)/2;
        vector<ll> dp(n+1);
        int p2 = n;
        set<pair<ll,int>> pos;
        pos.insert({dp[n],n});
        ll sum = 0;
        for(int j = n-1;i>= 0;j--){
            while(sum > m){
                sum -= a[p2-1];
                pos.erase({dp[p2],p2});
                p2--;
            }
            dp[j] = pos.begin()->first + a[j];
            pos.insert({dp[j], j});
            sum += a[j];
        }
        bool works = false;
        sum = 0;
        for(int j = 0; j < n;j++){
            if(sum <= m && dp[j] <= m)
                works = 1;
            sum += a[j];
        }
        if(works){
            high = mid;
        }else{
            low = mid;
        }
    }
    cout << low << endl;

    
}

signed main(){
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