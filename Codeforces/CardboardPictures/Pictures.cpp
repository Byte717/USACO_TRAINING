#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef unsigned long long ll;

using namespace std;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}
vector<ll> paintings;

void solve(){
    int n; ll c;
    cin >> n >> c;
    paintings = vector<ll>(n);
    for(ll &i : paintings){
        cin >> i;
    }

    function<ll(ll)> works = [&](ll x){
        ll total = 0;
        for(ll &i : paintings){
            if(total > c) break;
            total += (i+x+x)*(i+x+x);
        }
        return total; 
    };
    // cout << (113385729< MOD) << endl;
    ll low = 0, high = 1e9+7, ans;
    while(low <= high){
        ll mid = low + (high-low)/2;
        ll res = works(mid);
        if(res == c){
            ans = mid;
            break;
        }
        if(res < c){
            low = mid + 1;
        }else{
            high = mid - 1;
            ans = mid;
        }
        // cout << (low <= 113385729 && 113385729 <= high) << endl;
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("pictures.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}