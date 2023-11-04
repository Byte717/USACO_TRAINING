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

/*
what I learned routine Problem: revisit!
    - euclid's algorithm to find gcd


*/


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a*b == c*d){
        cout << 0 << '/' << 1 << endl;
        return 0;
    }
    if(a*b < c*d){
        ll p = c*a*b - d*a*a, q = c*a*b;
        ll d = __gcd(p,q);
        cout << p/d << '/' << q/d << endl;
    }else{
        ll p = d*a*b - c*b*b, q = d*a*b;
        ll d = __gcd(p,q);
        cout << p/d << '/' << q/d << endl;
    }
    return 0;
}