#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;


void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++) cin >> arr[i];
    int r = 0;
    for(int i = 0; i < n;i++){
        if(arr[min(n-1,r+1)] <= arr[min(n-1,i+1)]){
            r = i;
        }
    }
    vector<int> ans;
    for(int i = r+1; i < n;i++) ans.push_back(arr[i]);
    ans.push_back(arr[r]);
    for(int i = r-1; i >= 0;i--){
        if(arr[i] > arr[0]){
            ans.push_back(arr[i]);
        }else{
            for(int j = 0; j <= i;j++){
                ans.push_back(arr[j]);
            }
            break;
        }
    }
    for(auto e : ans) cout << e << ' ';
    cout << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("flip.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}