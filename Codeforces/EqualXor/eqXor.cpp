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
    int n, k; cin >> n >> k;
    k *= 2;
    vector<int> left(n), right(n);
    for(int i = 0; i < n;i++){
        cin >> left[i];
    }
    for(int i = 0;i < n;i++){
        cin >> right[i];
    }
    vector<int> occ(n+1,0);
    for(int i = 0; i < n;i++){
        occ[left[i]]++;
    }
    vector<int> zeroTimes, once, twice;
    for(int i = 1;i <= n;i++){
        if(occ[i] == 0) zeroTimes.push_back(i);
        else if(occ[i] == 1)once.push_back(i);
        else twice.push_back(i);
    }
    int v = 0;
    for(auto x : twice){
        if(v < k){
            v += 2;
            cout << x << " " << x << " ";
        }
    }
    for(auto x : once){
        if(v < k){
            v++;
            cout << x << ' ';
        }
    }
    cout << endl;
    v = 0;
    for(auto x : zeroTimes){
        if(v < k){
            v += 2;
            cout << x << " " << x << " ";
        }
    }
    for(auto x : once){
        if(v < k){
            v++;
            cout << x << ' ';
        }
    }
    cout << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}