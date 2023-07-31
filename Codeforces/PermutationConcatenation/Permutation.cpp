#include <bits/stdc++.h>
#define INF 1e18
#define MOD 998244353
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
int factorial(int n){
    int ret = 1;
    for(int i = 2; i <= n; i++){
        ret *= i;
    }
    return ret;
}



int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;
    ll ans = factorial(n);
    

    return 0;
}