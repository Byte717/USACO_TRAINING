#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

struct Monst{
    ll a, d;
    bool killed = false;
};

void solve(){
    int n; cin >> n;
    vector<Monst> monsters(n);
    for(auto &[a,d, _] : monsters){
        cin >> a >> d;
        _ = false;
    }

    set<int> nextKill;
    vector<ll> damage(n);
    for(int i = 0; i < n;i++){ // simulate first round
        if(i == 0){
            damage[i+1] += monsters[i].a;
        }else if(i == n-1){
            damage[i-1] += monsters[i].a;
        }else{
            damage[i+1] += monsters[i].a;
            damage[i-1] += monsters[i].a;
        }
    }
    int r1 = 0;
    for(int i = 0; i < n;i++){
        if(damage[i] > monsters[i].d){
            r1++;
            if(i != 0){
                nextKill.insert(i-1);
            }
            if(i != n-1){
                nextKill.insert(i+1);
            }
        }
    }
    cout << r1 << endl;
    for(int round = 0; round < n-1;round++){
        for(auto &i : nextKill){
            
        }
    }    
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}