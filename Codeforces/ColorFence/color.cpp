#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int v; cin >> v;
    if(v == 0){
        cout << -1 << endl;
        return 0;
    }
    vector<int> cost(9);
    for(int i = 0; i < 9;i++){
        cin >> cost[i];
    }
    string biggestDigits = "";
    int temp = v;
    for(int i = 8;i >= 0;i--){
        if(temp == 0) break;
        temp = cost[i]
    }
    return 0;
}