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


vector<int> reversed(vector<int> x){
    reverse(all(x));
    return x;
}
void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(auto &x : a){
        cin >> x;
    }
    for(auto &x : b){
        cin >> x;
    }
    cout << ((a == b || a == reversed(b)) ? "Bob" : "Alice") << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}