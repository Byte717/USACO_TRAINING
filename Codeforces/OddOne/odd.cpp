#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;



int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        map<int,int> cnt;
        int a, b, c; cin >> a >> b >> c;
        cnt[a]++;
        cnt[b]++;
        cnt[c]++;
        for(auto &[x,y] : cnt){
            if(y==1){
                cout << x << endl;
                break;
            }
        }
    }
    return 0;
}