#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }

    k = min(k,n);
    int last = n-1;
    while(k--){
        if(a[last] > n){
            cout << "NO" << endl;
            return;
        }
        last += n - a[last];
        if(last >= n){
            last -= n;
        }
    }
    cout << "YES" << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}