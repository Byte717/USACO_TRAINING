#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}


void solve(){
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    if(a[0] != 1){
        cout << 1 << endl;
        return;
    }
    ll j = 0, x = 1;
    /*
        a number that is between a[i] and a[i+1] will move to x - i;
        so the process will be simulated backwards, 
    */
    while(k--){ // simulate moving forward for each day
        while(j < n && a[j] <= x+j){ // while the 
            j++;
        }
        x+=j;
    }
    cout << x << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("ntarsis.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}