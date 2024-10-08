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
    int n;cin >> n;
    vector<int> points(n);
    // vector<bool> taken(102);
    for(int i = 0; i < n;i++){
        cin >> points[i];
        // taken[points[i]] = true;
    }
    if(n != 2){
        cout << "NO" << endl;
    }else{// there needs to be an integer point in between 
        sort(all(points));
        if(points[0]+1 == points[1]){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
    // for(int pt = 1; pt < 102;pt++){
    //     if(taken[pt]) continue;
    //     for(int i = 0; i < n;i++){

    //     }
    // }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("point.in","r",stdin);
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