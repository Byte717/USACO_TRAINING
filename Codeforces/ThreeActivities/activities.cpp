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

vector<int> _3best(vector<int> a){
    int mx1 = -1, mx2 = -1, mx3 = -1;
    for(int i = 0;i < a.size();i++){
        if(mx1 == -1 || a[i] > a[mx1]){
            mx3 = mx2;
            mx2 = mx1;
            mx1 = i;
        }else if(mx2 == -1 || a[i] > a[mx2]){
            mx3 = mx2;
            mx2 = i;
        }else if(mx3 == -1 || a[i] > a[mx3]){
            mx3 = i;
        }
    }
    return {mx1, mx2, mx3};
}

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for(auto & x : a) cin >> x;
    for(auto & x : b) cin >> x;
    for(auto & x : c) cin >> x;
    vector<int> bestA = _3best(a), bestB = _3best(b), bestC = _3best(c);
    int ans = 0;
    for(auto &i : bestA){
        for(auto &j : bestB){
            for(auto &k : bestC){
                if(i != j && i != k && j != k){
                    ans = max(ans, a[i] + b[j] + c[k]);
                }
            }
        }
    }
    cout << ans << endl;
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