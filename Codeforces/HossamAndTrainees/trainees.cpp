#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

void solve(){
    int n; cin >> n;
    map<ll,ll> factors;
    for(int i = 0; i < n;i++){
        ll a; cin >> a;
        for(ll x = 2; x*x <= a;x++){
            if(a % x == 0){
                factors[x]++;
            }
        }
    }
    for(auto &[x,y] : factors){
        if(y >= 2){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("trainees.in","r",stdin);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}