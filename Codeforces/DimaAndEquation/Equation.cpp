#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

/*
what I learned Dima Equation:
    - sum of digits is very small, so iterate through that for number thoery to speed it up

*/

ll S(ll x){
    ll ans = 0;
    while(x > 0){
        ans+= x%10;
        x /=10;
    }
    return ans;
}

ll aPowB(ll a, ll b){
    ll ret = 1;
    while(b--){
        ret*=a;
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("equation.in","r",stdin);
    ll a, b, c; cin >> a >> b >> c;
    ll n = 0;
    vector<ll> ans;
    for(int s = 1; s <= 81;s++){
        ll x = b*aPowB(s,a) + c;
        if(S(x) == s && x < 1000000000){
            n++;
            ans.push_back(x);
        }
    }
    cout << n << endl;
    for(auto &i : ans){
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}