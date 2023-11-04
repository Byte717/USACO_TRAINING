#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;
/*
Solution: a number isn't strongly composite if its a prime or its the product of 2 distint primes
- however, its composite if its a product of the same prime. so we break each number in a into its prime factors
- for all the prime numbers, we can take 2 of the same, or 3 different primes.
- so we keep dividing by 2 and adding the remainder, and add remainder/3 to the answer

What I learned Strongly Composite:
    - Break numbers into their factors for number theory
    - x = p1^d1 * p2^d2... pm^dm, meaning there can be more than one of a factor
*/


void solve(){
    int n; cin >> n;
    map<int,int> a;
    for(int i = 0; i < n;i++){
        int x; cin >> x;
        for(int j = 2; j*j <= x;j++){
            while(x % j == 0){
                x /= j;
                a[j]++;
            }
        }
        if(x != 1){
            a[x]++;
        }
    }
    int res = 0, remainder = 0;
    for(auto&[num,count] : a){
        res += count /2;
        remainder += count %2;
    }
    res += remainder / 3;
    cout << res << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("composite.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}