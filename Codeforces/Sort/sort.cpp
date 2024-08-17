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
    int n,q; cin >> n >> q;
    string a, b; cin >> a >> b;
    vector<vector<int>> pref1(n+1, vector<int>(26,0)), pref2(n+1, vector<int>(26,0));
    for(int i = 0; i < n;i++){
        pref1[i+1][a[i] - 'a']++;
        for(int c = 0;c<26;c++){
            pref1[i+1][c]+= pref1[i][c];
        }
    }
    for(int i = 0; i < n;i++){
        pref2[i+1][b[i] - 'a']++;
        for(int c = 0;c<26;c++){
            pref2[i+1][c]+= pref2[i][c];
        }
    }
    while(q--){
        int l, r; cin >> l >> r;
        int diff = 0;
        for(int c = 0; c < 26;c++){
            int stringA = pref1[r][c] - pref1[l-1][c];
            int stringB = pref2[r][c] - pref2[l-1][c];
            if(stringA > stringB){
                diff += abs(stringA-stringB);
            }
        }
        cout << diff << endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("sort.in","r",stdin);
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