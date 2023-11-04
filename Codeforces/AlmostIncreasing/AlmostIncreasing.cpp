#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    vector<int> pref(n-1);
    for(int i = 1; i < n-1;i++){
        int downhill = a[i-1] >= a[i] && a[i] >=a[i+1];
        pref[i] = pref[i-1] + downhill;
    }
    while(q--){
        int l,r; cin >> l >> r;
        l--; r--;
        if(l == r){
            cout << 1 << endl;
        }else{
            cout << ((r-l+1) - pref[r-1] + pref[l]) << endl;
        }
    }
    return 0;
}