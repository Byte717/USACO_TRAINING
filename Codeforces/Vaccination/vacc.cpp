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

template<typename T> inline bool flipped(T a,int i){return a&(1ll<<i);}
template<typename T> inline T pow2(int exp){return (1ll << exp);}

void solve(){
    int n,m,d,w,i,j;
    cin>>n>>m>>d>>w;
    d+=w;
    vector<int> a(n);
    cin>>a;
    int r=0,res=0,lst=0;
    for (int x:a)
    {
        if (!res||x>lst) lst=x+d,res=m-1,++r;
        else --res;
    }
    cout<<r<<'\n';
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