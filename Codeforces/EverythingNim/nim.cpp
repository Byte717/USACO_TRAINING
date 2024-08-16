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
    int n; cin >> n;
    vector<int> a(n);
    for(auto & x : a) cin >> x;
    int mx = *max_element(all(a));
    sort(all(a));
    int mex = 1;
    for(auto & x:a){
        if(x == mex){
            mex+=1;
        }
    }    
    if(mex > mx){
        if(mx %2 == 1){
            cout << "Alice" << endl;
        }else{
            cout << "Bob" << endl;
        }
    }else{
        if(mex%2 == 1){
            cout << "Alice" << endl;
        }else{
            cout << "Bob" << endl;
        }
    }

}

int main(){
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