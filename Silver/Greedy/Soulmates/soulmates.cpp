#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

ll solve(ll a, ll b){
    if(a==b){
        return 0;
    }else if(a > b){
        ll isOdd = a%2;
        return 1 + isOdd + solve((a+isOdd)/2, b); // if odd, we add 1, and keep dividing by 2
    }else{
        ll isOdd = a%2;
        return min(b-a, 1 + isOdd + solve(a,b/2)); // 2 options, we just keep adding 1 until we get to b, or we add 1 is a is odd, and multiply by 2(which is equal to dividing b by 2)
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;
    while(n--){
        ll a, b; cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}