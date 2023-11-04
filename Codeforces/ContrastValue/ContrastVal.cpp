#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;
/*
solution, you can delete an element if the element before is less than it and the element after is more
same thing applies if the element before is greater and the element after is smaller. 

What I learned Contrast Value:
-For minimizing, considering greedily what can be removed
-Use a condition, like in dp

*/


void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    n = unique(all(arr))-arr.begin();
    int ans = n;
    for(int i = 0; i + 2 < n;i++){
        ans -= (arr[i] < arr[i+1] && arr[i+1] < arr[i+2]);
        ans -= (arr[i] > arr[i+1] && arr[i+1] > arr[i+2]);
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("val.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}