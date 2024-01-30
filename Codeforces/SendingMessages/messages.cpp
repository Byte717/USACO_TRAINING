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
    // freopen("message.in","r",stdin);
    int t; cin >> t;
    while(t--){
        ll n, f, a, b; cin >> n >> f >> a >> b;
        vector<ll> moment(n+1);
        moment[0] = 0;
        for(int i = 1;i <= n;i++){cin >> moment[i];}
        sort(all(moment));
        for(int i = 1; i <= n;i++){
            f -= min(a*(moment[i]-moment[i-1]), b);
        }
        cout << ((f > 0) ? "YES" : "NO") << endl;

    }
    return 0;
}