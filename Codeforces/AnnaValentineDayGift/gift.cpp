#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define debug

#ifndef debug
    #ifdef __GNUG__
        #pragma GCC optimize("O3","unroll-loops")
        #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
    #endif
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
    int n, m; cin >> n >> m;
    vector<string> arr(n);
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    vector<int> zeros(n);
    for(int i = 0; i < n;i++){
        for(auto & c : arr[i]){
            if(c == '0'){
                zeros[i]++;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n;i++){
        ans += arr[i].size() - zeros[i];
    }
    sort(all(zeros));
    reverse(all(zeros));
    for(int i = 0; i < n;i++){
        if(i%2) ans += zeros[i];
    }
    cout << (ans -1 >= m ? "Sasha" : "Anna") << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
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