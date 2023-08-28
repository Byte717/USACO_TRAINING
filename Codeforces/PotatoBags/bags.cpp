#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

const ll MAXN = 1e9;
vector<ll> ans;
void findDiv(ll y, ll k, ll n){
    for(ll i = k; i <= n;i+=k){
        if(i -y >= 1){
            ans.push_back(abs(i-y));
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("bags.in","r",stdin);
    ll y, k, n; cin >> y >> k >> n;
    findDiv(y,k,n);
    if(ans.size() == 0){
        cout << -1 << endl;
    }else{
        for(int i = 0; i < ans.size();i++){
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}