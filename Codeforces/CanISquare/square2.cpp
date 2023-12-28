#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

bool isPerfectSquare(ll n) {
    if (n < 0ll) {
        return false;
    }

    ll sqrtN = sqrt(n);
    return (sqrtN * sqrtN == n);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll sum = 0;
        for(int i = 0; i < n;i++){
            ll x; cin >> x;
            sum += x;
        }

        if(isPerfectSquare(sum) || sum == 1LL){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}