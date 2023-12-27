#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


void solve(){
    int n; cin >> n;
    vector<int> p(n);
    for(int &i : p) cin >> p[i];
    sort(all(p));
    reverse(all(p));
    int x, a, y, b; cin >> x >> a >> y >> b;
    if(y > x){
        swap(x,y);
        swap(a,b);
    }

    x = x/100.0d; y = y/100.0d;
    int k; cin >> k;
    // bin search for the x num of tickets, then, those x tickets must be the x biggest elements, which means that we can arrange the biggest ones in place of where A and B contribute, where both contribute, take the biggest

    auto works = [&](int tickets){
        int given = 0;
        int pt = 0;
        // first find positions where both contribute
        for(int i = 0; i < tickets;i++){
            if(i % a == 0 && i % b == 0){
                given += (p[pt])*(x+y);
                pt++;
            }
        }
        // then x
        for(int i = 0; i < tickets;i++){
            if(i % a == 0 && !(i % b == 0)){
                given += p[pt]*x;
                pt++;
            }
        }
        // then y
        for(int i = 0;i < tickets;i++){
            if(i % b == 0 && !(i % a == 0)){
                given += p[pt]*y;
                pt++;
            }
        }
        return given >= k;
    };



    int low = 1, high = n, mid, ans = -1;
    while(low <= high){
        mid = low + (high-low)/2;
        if(works(mid)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }  
    cout << ans << endl;

}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int q; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}