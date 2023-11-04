#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;


void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> rawCost(n);
    for(ll i = 0; i < n;i++){
        cin >> rawCost[i];
    }
    unordered_set<ll> hasInfinite;
    for(ll i = 0; i < k;i++){
        ll a; cin >> a;
        a--;
        hasInfinite.insert(a);
    }
    vector<vector<int>> recipe(n);
    for(ll i = 0; i < n;i++){
        ll x; cin >> x;
        for(ll j = 0; j < x;j++){
            ll a; cin >> a;a--;
            recipe[i].push_back(a);
        }
    }
    vector<ll> minCost(n,INT64_MAX);
    for(ll i = 0; i < n;i++){
        if(hasInfinite.count(i) != 0){
            minCost[i] = 0;
        }else if(recipe[i].size() == 0){
            minCost[i] = rawCost[i];
        }
    }

    function<ll(int)> dfs = [&](int potion){
        if(minCost[potion] != INT64_MAX){
            return minCost[potion];
        }
        ll total = 0;
        for(int &i : recipe[potion]){
            total+= dfs(i);
        }
        minCost[potion] = min(total,rawCost[potion]);
        return minCost[potion];
    };

    for(int i = 0; i < n;i++){
        if(minCost[i] == INT64_MAX){
            minCost[i] = dfs(i);
        }
    }
    for(int i = 0; i < n;i++){
        cout << minCost[i] << ' ';
    }
    cout << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("potions.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}