#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;
 
ll gcd(ll A, ll B) {
    if (B == 0)
        return A;
    return gcd(B, A % B);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    ll n; cin >> n;
    ll sum1 = 0, sum2 = 0, sumBefore = 0, sumTot = 0;
    vector<ll> x(n+1);
    for(ll i = 1; i <= n;i++){
        cin >> x[i];
        sum1+= x[i];
    }
    sort(x.begin()+1, x.end());
    for(ll i = 1; i <= n;i++){
        sum2 += x[i]*(i-1) - sumBefore;
        sumBefore += x[i];
    }
    sumTot = sum1 + 2 * sum2;
    ll GCD = gcd(sumTot, n);
    cout << sumTot/GCD << ' ' << n/GCD << endl;
    return 0;
}