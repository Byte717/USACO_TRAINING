#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

void binary_Search(vector<ll> a, int n){
    auto works = [&](int k){
        ll Curr = 0;
        for(int i = 0; i < n;i++){
            if(Curr >= k){
                if(Curr + a[i] < k){
                    Curr = k;
                }else{
                    Curr += a[i];
                }
            }else{
                Curr += a[i];
            }
        }
        return Curr;
    };


    ll low = -1e18, high = 1e18, ansK = -1;
    ll MXRating = -INF;
    while(low <= high){
        ll mid = low + (high-low)/2;
        ll res = works(mid);
        if(res > MXRating){
            ansK = mid;
            MXRating = res;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    cout << ansK << endl;
}


void solve(){
    int n;cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    binary_Search(a, n);
    // ll delta = 0, ans = 0, sum = 0, mx = 0;
    // for(int i  = 0; i < n;i++){
    //     sum += a[i];
    //     mx= max(mx,sum);
    //     if(sum - mx < delta){
    //         delta = sum - mx;
    //         ans = mx;
    //     }
    // }
    // cout << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("rating.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}