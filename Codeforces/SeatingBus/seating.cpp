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


void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x : a) {cin >> x;x--;}
    vector<bool> filled(n);
    filled[a[0]] = 1;
    for(int i = 1; i < n;i++){
        if(a[i] == 0){
            if(!filled[a[i]+1]){
                cout << "NO" << endl;
                return;
            }
        }else if(a[i] == n-1){
            if(!filled[a[i]-1]){
                cout << "NO" << endl;
                return;
            }
        }else{
            if(!filled[a[i]-1] && !filled[a[i]+1]){
                cout << "NO" << endl;
                return;
            }
        }
        filled[a[i]] = 1;
    }
    cout << "YES" << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("seating.in","r",stdin);
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}