#include <bits/stdc++.h>
#define INF 1e18
#define mod 1e9+7

typedef long long ll;

using namespace std; 

void solve(){
    int n; cin >> n;
    int ans = 0; 
    set<int> values;
    for(int i = 0; i < n;i++){
        int a; cin >> a;
        auto it = values.lower_bound(a);
        if(it == values.end()){
            values.insert(a);
            continue;
        }
        ans += distance(it, values.end());
        values.insert(a);
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("IC.in","r",stdin);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}