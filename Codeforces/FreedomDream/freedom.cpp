#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;
/*
given n programmers and m options, we need to find a combo where there will be an infinite loop.
so, if n == 1, then there can be no loop
and n/m has to be a clean number.
if not then its complicated:
think about the smallest divisor that divides n. 
if that divisior is smaller than n, then by some combo of votes, we can reach it and eventually get stuck in a loop
if not, no loop

so find the smallest factor from 1 to root(n), then if its > m, then no loop

WHat I learned Freedom:
    - For divisibility problems, check the divisors of the number

*/

void solve(){
    int n, m;cin >> n >> m;
    if(n==1){
        cout << "YES" << endl;
        return;
    }
    int d = -1;
    for(int i = 2; i*i <= n;i++){
        if(n % i == 0){
            d = i;
            break;
        }
    }
    if(d == -1 || d > n){
        d = n;
    }
    if(d > m){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("freedom.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}