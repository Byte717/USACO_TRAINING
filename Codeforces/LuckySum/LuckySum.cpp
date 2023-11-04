#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;
/* 
solution: to construct the luck numbers, use recusion. then use lower bound and jump numbers as one number is used more than once

What I learned Lucky Sum:
    - in number theory, thoink of how you can store and construct the numbers with limitations
    - whenever something repeats, think of what interval it repeats on
    - use lower bound to speed up queries.

*/

set<ll> S;
void addNum(ll x, ll r){
    S.insert(x);
    if(x < r){
        addNum(x*10+4, r);
        addNum(x*10+7,r);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("luckySum.in","r",stdin);
    ll l, r; cin >> l >> r;
    ll sum = 0;
    addNum(0,r);
    if(l == r){
        if(S.find(l) != S.end()){
            cout << l << endl;
        }else{
            cout << *(S.lower_bound(l)) << endl;
        }
        return 0;
    }
    while(l <= r){
        auto it = S.lower_bound(l);
        ll next = *it;
        sum += (min(next, r) - l + 1)*next;
        l = next + 1;
    }
    cout << sum << endl;
    return 0;
}