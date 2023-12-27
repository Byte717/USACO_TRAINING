#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;



int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(auto &i : a) cin >> i;
        if(a[0] == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}