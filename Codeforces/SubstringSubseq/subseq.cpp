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
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    int ans = n + m;
    for(int i = 0; i < m;i++){
        int j = i;
        for(auto c : a){
            if(j < m && c == b[j])j++;
        }
        ans = min(ans, n+m - (j-i));
    }
    cout << ans << endl;
    // map<char, int> cntb;
    // int n = a.size(), m = b.size();
    // for(int i = 0; i < m;i++){
    //     cntb[b[i]]++;
    // }
    // for(int i = 0; i < n;i++){
    //     if(cntb.find(a[i]) != cntb.end() && cntb[a[i]] > 0){
    //         cntb[a[i]]--;
    //     }
    // }
    // int left = 0;
    // for(auto &[x,y] : cntb){
    //     left+= y;
    // }
    // cout << left + n << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("seq.in","r",stdin);
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}