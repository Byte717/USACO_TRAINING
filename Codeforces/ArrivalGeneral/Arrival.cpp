#include <bits/stdc++.h>
#define INF 1e6
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("arrive.in","r",stdin);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    int MX = -1, mxIdx = -1;
    for(int i = 0; i < n;i++){
        if(a[i] > MX){
            MX = a[i];
            mxIdx = i;
        }
    }
    int MN = INF, mnIdx = -1;
    for(int i = 0; i < n;i++){
        if(a[i] <= MN){
            MN = a[i];
            mnIdx = i;
        }
    }
    int ans = 0;
    if(mnIdx == n-1){
    }else{
        ans += n-1 - mnIdx;
    }

    if(mxIdx == 0){
    }else{
        ans += mxIdx;
    }
    if(mnIdx < mxIdx){
        ans--;
    }
    cout << ans << endl;
    return 0;
}