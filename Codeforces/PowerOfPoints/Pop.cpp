#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

/*
solution: so each interval contributed b-a+1. So based on that, sort the points, then for each ith point as S, you need the sum of the past and future points
the formula is n+x[i]*(2*i-n) - sums before + sums after. 

What I learned Power of Points:
    - Prefix sums imply summation and vice versa.
    - intervals can be counted as their length
    - sort things, makes it easier. 

*/

void solve(){
    ll n; cin >> n;
    vector<pair<ll,ll>> x(n+1);
    ll s1 = 0, s2 = 0;
    for(ll i = 1; i <= n; i++){
        cin >> x[i].first;
        x[i].second = i;
        s2 += x[i].first;
    }
    vector<ll> ans(n+1);
    sort(x.begin()+1, x.end());
    for(ll i = 1; i <= n;i++){
        s2 -= x[i].first;
        s1 += x[i].first;
        ans[x[i].second] = n+x[i].first*(2*i-n)-s1+s2;
    }
    for(ll i = 1; i <= n;i++) cout << ans[i] << ' ';
    cout << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("pop.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}