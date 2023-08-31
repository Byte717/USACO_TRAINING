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
        freopen("fence.in","r",stdin);
    #endif
    ll n, k; cin >> n >> k;
    vector<ll> a(n), pref(n+1,0);
    for(ll i = 0; i < n;i++){
        cin >> a[i];
        pref[i+1] = pref[i] + a[i];
    }
    if(n == k){
        cout << 1 << endl;
        return 0;
    }
    ll mn = INF;
    ll ans = -1;
    for(ll i = 1; i + k-1 <= n;i++){
        if(pref[i+k-1] - pref[i-1] < mn){
            mn = pref[i+k-1] - pref[i-1];
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}