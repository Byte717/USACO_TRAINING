#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// #pragma GCC optimize("O3","unroll-loops")
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("game.in","r",stdin);
    int m; cin >> m;
    map<int,int> cnt;
    for(int q = 0; q < m;q++){
        int type; cin >> type;
        if(type == 1){
            int x; cin >> x;
            cnt[1<<x]++;
        }else{
            ll num; cin >> num;
            for(ll i = 30; i >= 0;i--){
                if(num > (1<<i) && num != 0){
                    num -= min(num/(1<<i), cnt[(1<<i)])*(1<<i);
                }
            }
            if(num == 0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}