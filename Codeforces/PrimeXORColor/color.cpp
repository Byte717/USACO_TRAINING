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
    int n;
    cin >> n;
    if (n < 6) {
        if (n == 1)
            cout << 1 << '\n' << "1" << '\n';
        else if (n == 2)
            cout << 2 << '\n' << "1 2" << '\n';
        else if (n == 3)
            cout << 2 << '\n' << "1 2 2" << '\n';
        else if (n == 4)
            cout << 3 << '\n' << "1 2 2 3" << '\n';
        else if (n == 5)
            cout << 3 << '\n' << "1 2 2 3 3" << '\n';
    } else {
        cout << 4 << '\n';
        for (int i = 1; i <= n; i++)
            cout << i % 4 + 1 << ' ';
        cout << '\n';
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