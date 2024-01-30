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
    vector<pair<int,int>> pts(4);

    for(int i = 0; i < 4;i++){
        cin >> pts[i].first >> pts[i].second;
    }
    sort(all(pts));
    int X = abs(pts[0].second - pts[1].second);
    cout << X*X << endl; 
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}