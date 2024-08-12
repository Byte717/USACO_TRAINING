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
    int xc, yc, k; cin >> xc >> yc >> k;
    if(k == 1){
        cout << xc << ' ' << yc << endl;
        return;
    }
    int sumX = xc*k, sumY = yc*k;
    vector<int> xList, yList;
    for(int i = 0; i < k-1;i++){
        xList.push_back(i);
        sumX-=i;
    }
    xList.push_back(sumX);
    for(int i = 0; i < k-1;i++){
        yList.push_back(i);
        sumY-=i;
    }
    yList.push_back(sumY);
    for(int i = 0; i < k;i++){
        cout << xList[i] << ' ' << yList[i] << endl;
    }

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("center.in","r",stdin);
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}