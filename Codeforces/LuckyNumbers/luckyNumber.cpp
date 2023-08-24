#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

vector<ll> nums;
void makeNumbers(ll n, int fours, int sevens){
    if(n > 1e10){
        return;
    }
    if(fours == sevens){
        nums.push_back(n);
    }
    makeNumbers(n*10 + 7, fours,sevens+1);
    makeNumbers(n*10+4, fours +1, sevens);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("luckyNumber.in","r",stdin);
    ll n; cin >> n;
    makeNumbers(4,1,0);
    makeNumbers(7,0,1);
    sort(all(nums));
    if(binary_search(all(nums), n)) cout << n << endl;
    else cout << *upper_bound(all(nums), n) << endl;
    return 0;
}