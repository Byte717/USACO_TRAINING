#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

// #define debug

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef debug
        freopen("flowers.in","r",stdin);
    #endif
    ll n; cin >> n;
    vector<ll> flowers(n);
    map<ll,ll> cnt;
    for(int i = 0; i < n;i++){
        cin >> flowers[i];
        cnt[flowers[i]]++;
    }
    sort(all(flowers));
    if(cnt.size() == 1){
        cout << 0 << ' ';
        cout << (n*(n-1))/2 << endl;
        return 0;
    }
    cout << flowers[n-1] - flowers[0] << ' ';
    cout << cnt[flowers[n-1]]*(cnt[flowers[0]]) << endl;
    return 0;
}