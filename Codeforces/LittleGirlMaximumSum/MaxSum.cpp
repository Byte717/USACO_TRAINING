#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef __int64 ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("maxSum.in","r",stdin);
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    for(ll i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(rall(a));
    vector<ll> mostNeeded(n+1,0);
    for(ll i = 0; i < q; i++){
        ll l, r; cin >> l >> r;
        l--; r--;
        mostNeeded[l]++;
        mostNeeded[r+1]--;
    }
    mostNeeded.pop_back();
    vector<ll> pref(n+1,0);
    for(ll i = 0; i < n;i++){
        pref[i+1] = pref[i] + mostNeeded[i];
    }
    pref.erase(pref.begin());
    sort(rall(pref));
    ll sum = 0;
    for(ll i = 0; i < n;i++){
        sum += (a[i] * pref[i]);
    }
    cout << sum << endl;
    return 0;
}