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
    int n; ll k;cin >> n >> k;
    vector<ll> hp(n);
    for(int i = 0; i < n;i++){
        cin >> hp[i];
    }
    int first = 0, last = n-1;
    bool attackFirst = true;
    int kills = 0;
    while(k > 0 && first <= last){
        ll damage = min(k, hp[(attackFirst ? first : last)]);
        if(attackFirst){
            if(hp[first] - damage <= 0) {
                kills++;
                first++;
            }else{
                hp[first] -= damage;
            }
        }else{
            if(hp[last] - damage <= 0) {
                kills++;
                last--;
            }else{
                hp[last] -= damage;
            }
        }
        k -= damage;
        attackFirst = !attackFirst;
    }
    cout << kills << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("deep.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}