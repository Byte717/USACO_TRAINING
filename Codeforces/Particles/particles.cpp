#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}


void solve(){
    int n; cin >> n;
    vector<ll> c(n);
    ll mx = -INF;
    for(int i = 0; i < n;i++){
        cin >> c[i];
        mx = max(mx,c[i]);
    }
    bool allNeg = true;
    for(int i = 0; i < n;i++){
        if(c[i] > 0){
            allNeg = false;
            break;
        }
    }
    if(allNeg){
        cout << mx << endl;
    }else{
        ll evens = 0, odds = 0;
        for(int i = 0; i < n;i++){
            if(i % 2 == 0){
                evens += ((c[i] < 0) ? 0 : c[i]);
            }else if(i % 2 == 1){
                odds += ((c[i] < 0) ? 0 : c[i]);
            }
        }
        cout << max(evens, odds) << endl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("particles.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}