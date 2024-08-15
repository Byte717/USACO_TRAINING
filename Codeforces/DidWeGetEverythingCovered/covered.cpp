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
    int n,k,m; cin >> n >> k >> m;
    string s; cin >> s;
    vector<bool> found(k);
    string res = "";
    int count = 0;
    for(char c : s){
        if(res.size() == n){
            break;
        }
        count += (!found[c-'a']);
        found[c-'a'] = true;
        if(count == k){
            fill(all(found), false);
            count = 0;
            res += c;
        }
    }
    if(res.size() == n){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
         for(int i=0;i<k;i++){
            if(!found[i]){
                while(res.size()<n)
                    res+=(char)('a'+i);
            }
        }
        cout<<res<<"\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
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