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
    int n; cin >> n;
    string s; cin >> s;
    int last = -1;
    int zeros = 0, ones = 0;
    for(int i = 0; i < n;i++){
        if(s[i] == '0'){
            if(last == -1){
                last = i;
            }
        }else{
            if(last != -1){
                last = -1;
                zeros+=1;
            }
            ones++;
        }
    }
    if(last != -1) zeros++;
    cout << (ones > zeros ? "Yes" : "No") << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("majority.in","r",stdin);
    #ifdef LOCAL
	auto _clock_start = chrono::high_resolution_clock::now();
    #endif 
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    #ifdef LOCAL
    cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
        chrono::high_resolution_clock::now()
            - _clock_start).count() << "ms." << endl;
    #endif
    return 0;
}