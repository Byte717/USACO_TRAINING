#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;


void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    if(a[n-1] == 1){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<int> ans;
    while(a.size()){
        int pos = 0; 
        while(a[pos] != 0){
            pos++;
        }
        pos++;
        // a.erase(a.begin(), a.begin()+pos);
        for(int i = 0; i < pos-1;i++){
            a[i] = 0;
        }
        a.erase(a.begin());
        ans.push_back(pos-1);
    }
    reverse(all(ans));
    for(int i = 0; i < n;i++){
        cout << ans[i] << ' ';
    }
    cout << endl;

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("zero.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}