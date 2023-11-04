#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

// #define debug

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef debug
        freopen("cut.in","r",stdin);
    #endif
    int n, a,b,c; cin >> n >> a >> b >> c;
    int aLimit = n/a, bLimit = n/b, cLimit = n/c;
    map<int,int> m;
    for(int i = 0; i <= cLimit;i++){
        m.insert({n-(i*c),i});
    }
    int ans = -1;
    for(int i = 0; i <= aLimit;i++){
        for(int j = 0; j <= bLimit;j++){
            if(m.count(i*a+j*b) != 0){
                ans = max(ans, i + j + m[i*a+j*b]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}