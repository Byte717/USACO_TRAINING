#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

/*
what I learned sumProduct:
    - think of mathematical ideas. like multiplication and addition can be the quadratic formula
    - square roots can be found quick with binary search.
*/

map<ll,ll> cnt;

ll root(ll x){
    ll l = 0, r = 5000000001;
    while(r-l > 1){
        ll mid = (l+r)/2;
        if(mid*mid <= x) l = mid;
        else r = mid;
    }
    return l; 
}

ll get(ll b, ll c){
    ll discriminant = b*b -(4LL*c);
    if(discriminant < 0) return 0;
    ll x1 = (b-root(discriminant))/2;
    ll x2 = (b+root(discriminant))/2;
    if(x1 + x2 != b || x1*x2 != c) return 0;
    if(x1 == x2) return cnt[x1]*(cnt[x1]-1)/2;
    else return cnt[x1]*cnt[x2];
}

void solve(){
    cnt.clear();
    ll n; cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int q; cin >> q;
    while(q--){
        ll a, b; cin >> a >> b;
        cout << get(a,b) << ' ';

    }
    cout << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("sumProduct.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}