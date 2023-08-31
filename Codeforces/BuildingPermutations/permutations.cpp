#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

// #define debug

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef debug
        freopen("permutation.in","r",stdin);
    #endif
    vector<ll> change;
    // set<ll> have;
    ll n; cin >> n;
    for(ll i = 0; i < n;i++){
        ll x; cin >> x;
        change.push_back(x);
    }
    sort(all(change));
    ll ans = 0;
    for(int i = 0; i < n;i++){
        ans += abs(change[i]-(i+1));
    }
    cout << ans << endl;
    return 0;
}