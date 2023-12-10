#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

template <unsigned int NumBits> struct uint {
    uint64_t data : NumBits;
};
template <unsigned int NumBits> struct Int {
    int64_t data : NumBits;
};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    string s;
    for(int &i : a){
        cin >> i;
    }
    cin >> s;
    int x0 = 0, x1 = 0;
    for(int i = 0; i < n;i++){
        if(s[i] == '0'){
            x0 ^= a[i];
        }else{
            x1 ^= a[i];
        }
    }

    vector<int> pref(n+1,0);
    for(int i = 0; i < n;i++){
        pref[i+1] = pref[i] ^ a[i];
    }

    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int x,y; cin >> x >> y;
            int XOR = pref[y]-pref[x-1];
            x0^= XOR;
            x1 ^= XOR;
        }else{
            int x; cin >> x;
            if(x==0) cout << x0; 
            else cout << x1;
            cout << ' ';
        }
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
} 