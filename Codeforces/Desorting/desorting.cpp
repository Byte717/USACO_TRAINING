#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

/*
What I learned Desorting:
    - notice pattern in answer. it will be a common technique with a formula
*/

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    if(is_sorted(all(a)) == false){
        cout << 0 << endl;
        return;
    }
    ll diff = INF;
    for(int i = 1; i < n;i++){
        diff = min(diff, a[i]-a[i-1]);
    }
    cout << diff/2 + 1 << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("desort.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}