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


int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

void solve(){
    int n, l, r; cin >> n >> l  >> r;
    //greedily take the cards until you get in range
    vector<int> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i]; 
    }
    int right = 0, left = 0, sum = 0, ans = 0;
    while(left < n){
        while(right < n && sum < l){
            sum += a[right];
            right++;
        }

        if(l <= sum && sum <= r){
            ans++;
            left = right;
            sum = 0;
        }else{
            sum -= a[left];
            left++;
        }
    }
    cout << ans << endl;

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);   
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}