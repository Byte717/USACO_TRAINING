#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

// #define debug

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

vector<bool> prime((int)1e7+5,true);
void Sieve(){
    for(int x = 2; x <= 1e7+5;x++){
        if(!prime[x]) continue;
        for(int i = 2*x; i <= 1e7+5;i+=x){
            prime[i] = false;
        }
    }
    prime[0] = false;
    prime[1] = false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef debug
        freopen("hungry.in","r",stdin);
    #endif
    int n; cin >> n;
    Sieve();

    int printed = 0;
    for(ll i = 2; i < 1e7+5;i++){
        if(printed == n){
            break;
        }
        if(prime[i]){
            cout << i << ' ';
            printed++;
        }
    }
    cout << endl;
    return 0;
}