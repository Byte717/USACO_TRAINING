#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define debug

#ifndef debug
    #pragma GCC optimize("O3","unroll-loops")
    #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#endif

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;



void solve(){
    ll h, c, t; cin >> h >> c >> t;
    if(t <= (h+c)/2){
        cout << 2 << endl;
        return;
    }

    ll low = 1, high = 1e7, ans = 0;// ternay search on K, doesn't work, just make sure
    while(high - low > 2){
        ll mid1 = (2*low + high)/3, mid2 = (low + 2*high)/3;
        ll curAvg1 = ((mid1)*h + ((mid1-1)*c))/(2*(mid1-1)),curAvg2 = ((mid2)*h + ((mid2-1)*c))/(2*(mid2-1));
        if(abs(curAvg1 - t) <= abs(curAvg2-t)){
            high = mid2;
        }else{
            low = mid1;
        }
    }
    long double minA = 1e9;
    for(int x= min(1LL, low -1); x<=high+2;x++){
        ll cur =  ((x)*h + ((x-1)*c))/(2*(x-1));
        if(abs(cur-t) < minA){
            minA = (long double)abs(cur-t);
            ans = x;
        }
    }
    cout << 2*ans -1 << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("water.in","r",stdin);
    ll t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}