#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

const ll MAXN = 1e6;
set<ll> nums;
void init(ll x){
    if(x > MAXN){
        return;
    }
    if(x != 0LL) nums.insert(x);
    init(x*10LL+4LL);
    init(x*10LL+7LL);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("luck.in","r",stdin);
    init(0);
    ll n; cin >> n;
    ll numDigits = 0;
    while(n > 0){
        ll digit = n % 10;
        if(digit == 7 || digit == 4){
            numDigits++;
        }
        n/=10;
    }
    if(nums.find(numDigits) != nums.end()){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}