#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// #pragma GCC optimize("O3","unroll-loops")
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

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
    vector<ll> cities(n);
    for(int i = 0; i < n;i++){
        cin >> cities[i];
    }
    vector<ll> diffLeft, diffRight;
    diffRight.push_back(1);
    for(int i = 1; i < n-1;i++){
        ll leftDist = cities[i] - cities[i-1], rightDist = cities[i+1] - cities[i];
        if(leftDist > rightDist){
            diffRight.push_back(1);
            diffLeft.push_back(leftDist);
        }else{
            diffRight.push_back(rightDist);
            diffLeft.push_back(1);
        }
    }
    diffLeft.push_back(1);
    vector<vector<int>> pref(2, vector<int>(n+1,0));
    for(int i = 0; i < n;i++){
        pref[0][i+1] = pref[0][i] + diffRight[i];
    }
    for(int i = 0; i < n;i++){
        pref[1][i+1] = pref[1][i] + diffLeft[i];
    }
    pref[1][n] = pref[1][n-1];
    pref[0][n] = pref[0][n-1];
    int m; cin >> m;
    while(m--){
        int x, y; cin >> x >> y;
        if(y > x){
            cout << pref[0][y-1] - pref[0][x-1] << endl;
        }else{
            cout << pref[1][x-1] - pref[1][y-1] << endl;
        }
    }

}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("city.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}