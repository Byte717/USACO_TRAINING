#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;



int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n;i++){
            cin >> a[i];
        }
        if(n == 1){
            cout << a[0] << endl;
            continue;
        }
        if(n == 2){
            cout << a[0] << ' ' << ((a[0] + a[1])/2)*2 << endl;
            continue;
        }
        ll sum = 0, odd = 0;
        for(int i = 0; i < n;i++){
            sum += a[i];
            if(a[i]&1) odd++;
            if(i == 0){
                cout << sum << ' ';
            }else{
                if(odd == 3){
                    sum--;
                    odd = 0;
                }
                if(sum &1 ) cout << sum-1 << ' ';
                else cout << sum << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}