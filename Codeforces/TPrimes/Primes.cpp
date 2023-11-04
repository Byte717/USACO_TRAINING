#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

/*
for there to be 3 factors, the number has to be a perfect square and the root needs to be prime
- so we use the Sieve of Ereskjd;laskj to find if a number is prime
and we check the root of each number;

What I learned T-primes:
    - use the Sieve to find prime numbers for number theory

*/


const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

vector<bool> prime((int)1e6+5,true);
void Sieve(){
    for(int x = 2; x <= 1e6+2;x++){
        if(!prime[x]) continue;
        for(int i = 2*x; i <= 1e6;i+=x){
            prime[i] = false;
        }
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("primes.in","r",stdin);
    Sieve();
    int n; cin >> n;
    for(int i = 0; i < n;i++){
        ll x; cin >> x;
        if(x == 1){
            cout << "NO" << endl;
            continue;
        }
        ll root = sqrt(x);
        if(root * root == x && prime[root]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}