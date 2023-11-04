#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n+5), pref(n+5);
    string s; cin >> s;
    for(int i = 1; i <= n;i++){
        a[i] = (s[i] == '+') ? 1 : -1;
    }
    pref[0] = 0;
    for(int i = 1; i <= n;i++){
        p[i] = p[i-1] + ((i%2 == 1) ? a[i] : -a[i]);
    }
    while(q--){
        int l, r; cin >> l >> r;
        int sum;
        if(l > r){
            sum = 0;
        }else{
            if(l % 2 == 1) sum = pref[r] - pref[l-1];
            else sum = pref[l-1] - pref[r];
        }
        if(sum == 0){
            cout << 0 << endl;
            continue;
        }
        if((r-l+1) % 2 == 0){
            cout << 2 << endl;
        }else{
            cout << 1 << endl;
        }
    }

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