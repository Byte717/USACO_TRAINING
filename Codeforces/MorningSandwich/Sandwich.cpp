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
    int b, c,h; cin >> b >> c >> h;
    int ans = b;
    int gaps = b-1;
    // if(c >= h){
    //     if(c >= gaps){
    //         cout << ans + gaps << endl;
    //     }
    // }else{
    //     if(h >= gaps){
    //         cout << ans + gaps << endl;
    //     }else{
    //         int leftOver = gaps - h;
    //         ans += h;
    //         if(c > leftOver){
    //             cout << ans + leftOver << endl;
    //         }else{
    //             cout << 
    //         }
    //     }

    // }
    if(c + h >= gaps){
        cout << ans + gaps << endl;
    }else{
        gaps = c + h;
        int breadSlices =  gaps+1;
        cout << breadSlices + gaps << endl;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("Sandwich.in","r",stdin);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}