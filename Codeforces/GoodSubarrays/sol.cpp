#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n, cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    vector<int> pref(n+1,0);
    for(int i = 0; i < n;i++){
        pref[i+1] = pref[i] + a[i];
    }
    map<int, int> cnt;
    int ans = 0;
    for(int i = 0; i < n;i++){
        int p = pref[i+1] - i+1;
        if(cnt.find(p) != cnt.end()){
            ans += (cnt[p]*(cnt[p]-1))/2;
        }
        cnt[p]++;
    }
    cout << ans << endl;
    return 0;
}