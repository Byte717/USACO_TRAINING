#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

struct X{
    ll n;
    ll pow;
};
vector<X> PrimeFactors(ll n){
    vector<X> ret; 
    for(ll i = 2; i*i <= n;i++){
        ll pow = 0;
        while(n% i == 0){
            pow++;
        }
        ret.push_back({i, pow});
        n /= (i*pow);
    }
    if(n > 1){
        ret.push_back({n,1});
    }
    return ret;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("div.in","r",stdin);
    ll n; cin >> n;
    int ans = 0;
    for(ll p = 2; p*p <= n;p++){
        int exp = 0;
        while(n%p == 0){
            exp++;
            n/= p;
        }

        for(int i = 1; exp - i >= 0;i++){ // for some p^e, we can choose p^1, p^2, p^ 3 etc,
            exp -= i;
            ans++;
        }
    }
    if(n > 1){ans++;}
    cout << ans << endl;
    return 0;
}