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


struct Element{
    int value;
    int color;
};

void solve(){
    int n; cin >> n;
    vector<Element> elements(n);
    for(int i = 0; i < n;i++){
        cin >> elements[i].value;
    }
    for(int i = 0; i < n;i++){
        cin >> elements[i].color;
    }
    map<int, vector<int>> colorMap;
    for(int i = 0; i < n;i++){
        colorMap[elements[i].color].push_back(elements[i].value);
    }
    map<int, vector<int>> prefMap;
    for(auto &[color, vals] : colorMap){
        vector<int> pref(n+1,0);
        for(int i = 0; i < vals.size();i++){
            pref[i+1] = pref[i] + vals[i];
        }
        pref.erase(pref.begin());
        prefMap[color] = pref;
    }
    map<int,int> increment;
    int totalSum = 0;
    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int color, X; cin >> color >> X;
            increment[color] += X;
            totalSum += X;
        }else{
            int color, Y; cin >> color >> Y;
            int totalBump = totalSum - increment[color]; // how much this color's values increased
            auto it = upper_bound(all(prefMap[color]), Y - totalBump);
            if(it == prefMap[color].begin()){
                cout << 1 << endl;
            }else{
                cout << distance(prefMap[color].begin(), prev(it)) << endl;
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("array.in","r",stdin);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}