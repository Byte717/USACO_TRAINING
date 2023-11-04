#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

// #define debug

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

const int dirX[4] = {-1, 0, 1, 0};
const int dirY[4] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

void solve(){
    int n; cin >> n;
    vector<int> b(n);
    for(int i = 0; i < n;i++){
        cin >> b[i];
    }
    vector<int> pref(n), suff(n);
    for(int i = 0; i < n;i++){
        pref[i] = b[i] + i;
        suff[i] = b[i] - i;
    }
    for(int i = 1; i < n;i++){
        pref[i] = max(pref[i],pref[i-1]);
    }
    for(int i = n-2; i >= 0; i--){
        suff[i] = max(suff[i],suff[i+1]);
    }
    int ans = 0;
    for(int m = 1; m < n-1; m++){
        ans = max(ans, b[m] + pref[m-1] + suff[m+1]);
    }
    cout << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef debug
        freopen("","r",stdin);
    #endif
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}