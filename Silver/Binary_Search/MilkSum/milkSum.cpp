#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("sum.in","r",stdin);
    int n; cin >> n;
    vector<ll> original(n);
    for(int i = 0; i < n;i++){
        cin >> original[i];
    }
    vector<ll> optimal = original;

    sort(all(optimal));
    ll originalSum = 0;
    for(int i = 0; i < n;i++){
        originalSum += (i+1)*optimal[i];
    }
    int q;cin >> q;
    while(q--){
        int idx; ll newVal; cin >> idx >> newVal;
        idx--;
        if(newVal == original[idx]){
            cout << originalSum << endl;
            continue;
        }
        auto originalIdx = lower_bound(all(optimal), original[idx]) - optimal.begin();
        auto newIdx = lower_bound(all(optimal), newVal) - optimal.begin();
        ll ans = originalSum - ((originalIdx+1)*original[idx]) + ((newIdx+1)*newVal);
        if(newIdx < originalIdx){
            for(int i = newIdx;i < originalIdx;i++){
                ans += optimal[i];
            }
        }else{
            for(int i = originalIdx;i < newIdx;i++){
                ans -= optimal[i];
            }
        }
        cout << ans << endl;
    }
    return 0;   
}