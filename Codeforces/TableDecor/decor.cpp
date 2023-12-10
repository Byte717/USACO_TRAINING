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
    // freopen("decor.in","r",stdin);
    ll r, g, b; cin >> r >> g >> b;
    ll a[3] = {r,g,b};
    sort(a,a+3);
    ll ans = 0;
    ans+= min((a[1]+a[2]+a[0])/3, a[0]+a[1]);
    cout << ans << endl;
    return 0;
}