#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("factory.in","r",stdin);
    ll a, m; cin >> a >> m;
    set<ll> remainders;
    while(true){
        ll rem = a % m;
        if(remainders.count(rem) > 0){
            cout << "No" << endl;
            break;
        }
        if(rem == 0){
            cout << "Yes" << endl;
            break;
        }
        remainders.insert(rem);
        a+= rem;
    }
    return 0;
}