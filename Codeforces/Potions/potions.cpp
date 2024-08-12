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


ll LOG2(ll n){
    ll ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(auto &x : a) cin >> x;
    ll sum = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(ll i = 0; i < n;i++){
        sum += a[i];
        pq.push(a[i]);
        while( sum < 0){
            sum -= pq.top();
            pq.pop();
        }
    }
    cout << pq.size() << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    ll t = 1;
    while(t--){
        solve();
    }
    return 0;
}