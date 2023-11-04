#include <bits/stdc++.h>
#define INF 1e18
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;
const ll MOD = 1e9+7;
using namespace std;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}
ll aModB(ll a , ll b) { if(a<0 ) { return ((a+(abs(a)/b)*b)+b)%b ; } else { return a%b; } }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    ll x, y; cin >> x >> y;
    ll n; cin >> n;
    ll ans;
    switch (n%6){
    case 0:
        ans = x-y;
        break;
    case 1:
        ans = x;
        break;
    case 2:
        ans = y;
        break;
    case 3:
        ans = y-x;
        break;
    case 4:
        ans = -x;
        break;
    case 5:
        ans = -y;
        break;
    default:
        break;
    }
    cout << aModB(ans,MOD) << endl;
    return 0;
}