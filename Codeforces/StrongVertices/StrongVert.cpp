#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

/*
what I learned Strong verticies:
    - maniplulate the mathematical conditions provided.

*/

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n;i++){cin >> a[i];}
    for(int i = 0; i < n;i++){cin >> b[i];}
    int MX = INT_MIN;
    for(int i = 0; i < n;i++) MX = max(MX, a[i]-b[i]);
    int c = 0;
    for(int i = 0; i < n;i++){
        if(a[i]-b[i] == MX){
            c++;
        }
    }
    cout << c << endl;
    for(int i = 0; i < n;i++){
        if(a[i]-b[i] == MX){
            cout << i + 1 << ' ';
        }
    }
    cout << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}