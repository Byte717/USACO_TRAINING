#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()


typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

/*
    - For 3 sides, a+b > c
    - for an n^2 solution
        - for 2 numbers a and b, keep a set of all the sides,
        - using the set, count how many c are there such that c < a+b
    - For N log n
        - iterate through the i numbers
        - potentially binary search?

*/


void solve(){
    ll n; cin >> n;
    vector<ll> sides(n);for(auto & x : sides){cin >> x;}
    map<ll,ll> cnt;
    for(ll i = 0; i < n;i++){
        cnt[sides[i]]++;
    }
    ll ans = 0;
    ll sum = 0;
    for(auto &[x,y] : cnt){
        if(y >= 3){
            ans += y*(y-1)*(y-2)/6; 
        }
        if(y >= 2){
            ans += y*(y-1)/2*sum;
        }
        sum += y;
    }
    cout << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("triangles.in","r",stdin);
    ll t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}