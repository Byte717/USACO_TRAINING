#include <bits/stdc++.h>
#define INF 1e18
#define MOD 998244353
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

int FACT[(int)1e6];

int factorial(int n){
    FACT[0] = 1;
    FACT[1] = 1;
    int ret = 1;
    for(int i = 2; i <= n; i++){
        ret *= i;
        FACT[i] = ret;
    }
    return ret;
}



int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;
    ll ans = factorial(n);
    

    return 0;
}