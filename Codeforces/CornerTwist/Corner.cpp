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
    int n,m;
    cin>>n>>m;
    vector<string> grid1, grid2;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        grid1.push_back(s);
    }
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        grid2.push_back(s);
    }
    int sr1[m]{}, sr2[m]{}, sc1[n]{}, sc2[n]{};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){// all the corresponding rows and cols need to have a same value for mod 3!!!!
            sr1[j] += (int)(grid1[i][j] - '0');
            sr1[j] %= 3;
            sr2[j] += (int)(grid2[i][j] - '0');
            sr2[j] %= 3;
            sc1[i] += (int)(grid1[i][j] - '0');
            sc1[i] %= 3;
            sc2[i] += (int)(grid2[i][j] - '0');
            sc2[i] %= 3;
        }
    }
     bool ok = 1;
    for(int i=0;i<n;i++){
        ok &= (sc1[i] == sc2[i]);
    }
    for(int i=0;i<m;i++){
        ok &= (sr1[i] == sr2[i]);
    }
    if(ok) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}