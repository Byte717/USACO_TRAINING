#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()
// #define debug
typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int power(int a, int e){
    if(e == 0) return 1;
    return (e==1) ? a : a*power(a,e-1);
}

void answer(int a, int b){
    cout << a << " + " << b << " = " << a+b << endl;
}

void solve(){
    int a, b, c; cin >> a >> b >> c;
    ll k; cin >> k;
    bool good = false;
    for(int i = power(10,a-1); i < power(10,a);i++){
        int left = max(power(10,b-1), power(10,c-1) - i);
        int right = min(power(10,b)-1, power(10, c) - 1 - i);

        if(left > right) continue;

        int have = right - left + 1;
        if(k <= have){
            answer(i, left + k -1);
            good = true;
            break;
        }
        k -= have;
    }
    if(!good){
        cout << -1 << endl;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef debug
        freopen("kth.in","r",stdin);
    #endif
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}