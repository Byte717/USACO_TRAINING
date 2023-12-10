#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int gcd(int x, int y){
    if(y == 0) return x;
    return gcd(y, x%y); 
}


int findGCD(vector<int> a){
    int res = a[0];
    for(int i = 1; i < a.size();i++){
        res = gcd(res, a[i]);
        if(res == 1) return 1;
    }
    return res;
}


void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int mx = -1;
    for(int i = 0; i > n;i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    vector<int> diffs;
    for(int i = 0; i < n;i++){
        if(a[i] == mx){
            continue;
        }
        diffs.push_back(abs(mx - a[i]));
    }
    int GCD = findGCD(diffs);
    int ans = 0;
    for(int i = 0; i < diffs.size();i++){
        ans += diffs[i]/GCD;
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