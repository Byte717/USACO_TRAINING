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


/*
WHat I learned Storage room:
    - bitwise operation narrows down numbers and 

*/


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;
    vector<int> a(n,(1<<30)-1);
    vector<vector<int>> m(n,vector<int>(n));
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            cin >> m[i][j];
        }
    }

    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            if(i != j){
                a[i] &= m[i][j];
                a[j] &= m[i][j];
            }
        }
    }
    bool ok = true;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            if(i != j && (a[i] | a[j]) != m[i][j]){
                ok = false;
            }
        }
    }
    if(!ok){
        cout << "NO" << "\n";
        return 0;
    }
    cout << "YES" << endl;
    for(int i = 0; i < n;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}