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
    for(int i = 0; i < n;i++) cin >> a[i];
    vector<bool> inverted(n, false);
    for(int i = 0; i < n-1;i++){
        inverted[i] = (a[i] >= a[i+1]);
    }
    set<int> inversions;
    for(int i = 0; i < n;i++){
        if(inverted[i]) inversions.insert(i+1);
    }
    inversions.insert(n);
    int ans = 0;
    for(set<int>::iterator it = inversions.begin(); it != inversions.end();++it){
        if(it == inversions.begin() || it == prev(inversions.end())) continue;
        int curIdx = *it, nextIdx = *next(it), prevIdx = *prev(it);
        ans = max(ans, nextIdx - prevIdx);
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("dzy.in","r",stdin);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}