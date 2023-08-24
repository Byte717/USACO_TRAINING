#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}
int gcd(int x, int y){
    if(y == 0) return x;
    return gcd(y, x%y); 
}
ll keepDividing(ll x){
    ll count = 0;
    while(x%2 == 0 || x%3 == 0 || x%5 ==0){
        if(x%2 == 0){
            x/=2;
            count++;
        }else if(x %3  == 0){
            x/=3;
            count++;
        }else if(x%5 == 0){
            x/=5;
            count++;
        }
    }
    if (x != 1){
        return -1;
    }
    return count;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    ll a,b; cin >> a >> b;
    if(a==b){
        cout << 0 << endl;
        return 0;
    }
    int p = __gcd(a,b);
    a/=p;
    b/=p;
    a = keepDividing(a);
    b = keepDividing(b);
    if(a == -1 || b == -1){
        cout << -1  << endl;
        return 0;
    }
    cout << a + b << endl;
    return 0;
}