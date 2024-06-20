#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


struct Move{
    ll damage;
    ll cooldown;
};

void solve(){
    ll h, n; cin >> h >> n;
    vector<Move> attacks(n);
    for(ll i = 0; i < n;i++){
        cin >> attacks[i].damage;
    }
    for(ll i = 0; i < n;i++){
        cin >> attacks[i].cooldown;    
    }
    ll curMoves = 0;
    priority_queue<pair<ll,pair<ll,ll>>, vector<pair<ll,pair<ll,ll>>>, greater<pair<ll,pair<ll,ll>>>> pq;
    for(ll i = 0; i < n;i++){
        pq.push({0,{attacks[i].damage, attacks[i].cooldown}}); // {renewTime, {damage, cooldown}}
    }
    while(h > 0){
        auto curAttack = pq.top(); 
        pq.pop();
        curMoves = curAttack.first;
        h -= curAttack.second.first;
        pq.push({curAttack.first + curAttack.second.second, curAttack.second});
    }
    cout << curMoves+1 << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("finalBoss.in","r",stdin);
    ll t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}