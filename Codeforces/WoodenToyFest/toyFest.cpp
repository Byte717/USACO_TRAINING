#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;


void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(all(a));
    auto works = [&](ll m){
        int i = 0;
        while(i < a.size() && a[i+1] - a[0] <= 2 * m){i++;}
        int j = n-1;
        while(j-1 >= 0 && a.back() - a[j-1] <= 2 *m){j--;}
        i++; j--;
        return (i > j || a[j]- a[i] <= 2*m);
    };

    ll low = -1, high = 1e9;
    while(high - low > 1){
        ll mid = (low+high) >> 1;
        if(works(mid)){
            high = mid;
        }else{
            low = mid;
        }
    }
    cout << high << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("toys.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}