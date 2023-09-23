#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("convention.in","r",stdin);
    ll n, m, c; cin >> n >> m >> c;
    vector<ll> times(n);
    for(ll i = 0; i < n;i++){
        cin >> times[i];
    }
    sort(all(times));
    auto works = [&](ll t){
        ll numBus = 0;
        ll capacity = 0;
        ll startTime = 0;
        for(ll i = 0; i < n;i++){
            if(times[i] - startTime > t || capacity == c){
                startTime = times[i];
                capacity = 1;
                numBus++;
            }else{
                capacity++;
            }
        }
        return numBus < m;
    };

    ll low = 0, high = times[n-1] - times[0], ans = -1;
    while(low <= high){
        ll mid = low + (high-low)/2;

        if(works(mid)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    freopen("convention.out","w",stdout);
    cout << ans << endl;
    return 0;
}