#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const int dirX[4] = {-1, 0, 1, 0};
const int dirY[4] = {0, 1, 0, -1};

void solve(){
    int n; ll k; cin >> n >> k;
    vector<pair<ll,ll>> intervals(n);
    for(int i = 0; i < n;i++){
        int l,r; cin >> l >> r;
        intervals[i].first = l;
        intervals[i].second = r;
    }
    sort(all(intervals));
    ll rem = 0, op = 0, ans = INF;
    for(auto &[l,r] : intervals){
        if(r-l + 1 >= k){
            ans = min(ans, (l+k-1LL) +op+2LL);
            break;
        }else if(r-l+1+rem >= k){
            ans = min(ans, op + r + 2LL + (k-(r-l+1LL))*2LL);
            // break;
        }
        if(r-l ==0){
            rem++;
        }else{
            // ll take = r - l + 1;
            k -= (r-l+1LL);
            op += 2LL;
        }
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("black.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}