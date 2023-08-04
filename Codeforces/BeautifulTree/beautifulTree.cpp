#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;


int n, m;
vector<int> arr;
int operationsNeeded(int left, int right){
    if(right - left == 1) return 0;
    int mid = (left+right) >> 1;
    int MXLeft = *max_element(arr.begin() + left, arr.begin() + mid);
    int MXRight = *max_element(arr.begin() + mid, arr.begin() + right);
    int ans = 0;
    if(MXLeft > MXRight){
        ans++;
        for(int i = 0; i < (mid-left);i++){
            swap(arr[left+i], arr[mid+i]);
        }
    }
    return ans + operationsNeeded(left,mid) + operationsNeeded(mid,right);
}

void solve(){
    int ans = operationsNeeded(0,m);
    if(is_sorted(all(arr))){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("tree.in","r",stdin);
    int t; cin >> t;
    while(t--){
        cin >> m;
        arr.resize(m);
        for(int i = 0; i < m;i++){
            cin >> arr[i];
        }
        solve();
    }
    return 0;
}