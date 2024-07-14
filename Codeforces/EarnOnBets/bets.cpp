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
    int n; cin >> n;
    vector<int> k(n);
    for(int i = 0; i < n;i++){
        cin >> k[i];
    }
    double sum = 0.0;
    for(int i = 0; i < n;i++){
        sum += (double)1/k[i];
    }
    if(sum < 1){
        int optimalS = 1;
        for(int i = 0; i < n;i++){
            optimalS = (optimalS*k[i]/__gcd(optimalS, k[i]));
        }
        for(int i = 0; i < n;i++){
            cout << optimalS/k[i] << " ";
        }
        cout << endl;
    }else{
        cout << -1 << endl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("bets.in","r",stdin);
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}