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

void solve(){
    int n, x, y; cin >> n >> x >> y;
    x--; y--;
    vector<int> a(n);
    for(int i = y; i <= x;i++){
        a[i] = 1;
    }
    for(int i = x+1; i < n;i++){
        a[i] = a[i-1]*-1;
    }
    for(int i = y-1;i >= 0;i--){
        a[i] = a[i+1]*-1;
    }
    for(int i = 0; i < n;i++){
        cout << a[i] << "\n"[i == n-1];
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}