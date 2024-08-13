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
    vector<int> a(n);
    map<int,vector<int>> idx;
    for(int i = 0; i < n;i++){
        cin >> a[i];
        idx[a[i]].push_back(i);
    }
    int m; cin >> m;
    while(m--){
        string s; cin >> s; 
        if(s.size() != n){
            cout << "NO" << endl;
            continue;
        }
        for()
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}