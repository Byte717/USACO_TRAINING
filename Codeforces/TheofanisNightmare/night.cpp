#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

template <unsigned int NumBits> struct uint {
    uint64_t data : NumBits;
};
template <unsigned int NumBits> struct Int {
    int64_t data : NumBits;
};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}


void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    reverse(all(a));
    vector<int> pref(n+1);
    pref[0] = 0;
    for(int i = 0; i < n;i++){
        pref[i+1] = pref[i] + a[i];
    }
    int ans = pref[n];
    for(int i = n-1;i >= 1;i--){
        if(pref[i] > 0){
            ans += pref[i];
        }
    }
    cout << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}