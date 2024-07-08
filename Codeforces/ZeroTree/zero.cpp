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

vector<vector<ll>> adj;
vector<ll> values;

pair<ll,ll> dfs(ll node, ll parent){
    pair<ll,ll> curAns = {0,0};
    for(auto & x : adj[node]){
        if(x != parent){
            auto subAns = dfs(x,node);
            curAns.first = max(curAns.first, subAns.first);
            curAns.second = max(curAns.second, subAns.second);
        }
    }
    ll curOps = curAns.first - curAns.second + values[node];
    if(curOps > 0)curAns.second += curOps;
    else curAns.first += (-curOps);
    return curAns;
}

void solve(){
    ll n; cin >> n;
    adj.resize(n);
    values.resize(n);
    for(ll i = 0; i < n-1;i++){
        ll a,b; cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    for(ll i = 0; i < n;i++){
        cin >> values[i];
    }
    auto [increments, decrements] = dfs(0,-1);
    cout << increments + decrements << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}