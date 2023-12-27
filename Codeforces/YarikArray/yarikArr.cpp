#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &i : a) cin >> i;

    int ans = INT32_MIN, cur = 0;
    for(int i = 0; i < n;i++){
        cur += a[i];
        if(ans < cur){
            cur = ans;
        }

        if(cur < 0){
            cur = 0;
        }
    }
    return ans;
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