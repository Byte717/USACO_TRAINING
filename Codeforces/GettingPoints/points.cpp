#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


void solve(){
    ll n, p, l, t; cin >> n >> p >> l >> t;
    ll low = 0, high = n, mid, ans = -1;
    while(low <= high){
        mid = low + (high-low)/2; // calculates the days needed to work
        if(mid*l + min(2*mid,(n+6)/7)*t >= p){ // minimize days needed to work to maximize days rested
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    cout << n-ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("points.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}