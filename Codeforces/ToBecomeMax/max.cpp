#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

/*
solution: we can binary search for an answer. to validate, we can loop through all i to see how many operations it would need to make a[i] = x;
form i to n, if

*/


void solve(){
    ll n, k; cin >> n >> k; 
    vector<ll> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];


    auto works = [&](int x){
        for(int i = 0; i < n;i++){
            if(a[i] >= x){
                return true;
            }
            ll totalUsed = x - a[i];
            bool valid = false;
            for(int j = i+1; j < n;j++){
                // if(j >=n) break;
                x--;
                if(a[j] >= x){
                    valid = true;
                    break;
                }else{
                    totalUsed += x - a[j];  
                } 
            }
            if(totalUsed <= k && valid) return true;
        }
        return false;
    };

    works(6);
    ll low = 0, high = *max_element(all(a)) + k, ans = 0;
    while(low <= high){
        ll mid = (low + high)/2;

        if(works(mid)){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("max.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}