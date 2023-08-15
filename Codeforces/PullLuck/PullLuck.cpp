#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

/*

What I learned Pull Luck:
    - the sum of numbers from 1 to 2*n is divisible by n; after that, the remainders repeat.
    - so check divisibility from 1 to 2*n

*/

void solve(){
    ll n, x; ll p; cin >> n >> x >> p;
    for(ll i = 1; i <= min(2*n,p);i++){
        ll pos = ((i*(i+1)/2));
        pos %= n;
        if(pos == (n-x)%n){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("pull.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}