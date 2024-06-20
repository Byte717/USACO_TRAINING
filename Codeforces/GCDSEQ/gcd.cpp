#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int gcd(int x, int y){
    if(y == 0) return x; return gcd(y, x%y); 
}


bool makesGood(vector<int>&a){
    int prevGcd = gcd(a[0],a[1]);
    for(int i = 1; i < a.size()-1;i++){
        if(prevGcd > gcd(a[i], a[i+1])) return false;
        prevGcd = gcd(a[i],a[i+1]);
    }
    return true;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    int prevGcd = -1;
    int indexToDel = -1;
    for(int i = 0; i < n-1;i++){
        if(prevGcd > gcd(a[i],a[i+1])){
            indexToDel = i;
            break;
        }
        prevGcd = gcd(a[i],a[i+1]);
    }
    if(indexToDel == -1){
        cout << "YES" << endl;
        return;
    }
    vector<int> b1 = a, b2 = a, b3 = a;
    if(indexToDel > 0) b1.erase(b1.begin() + indexToDel - 1);
    b2.erase(b2.begin() + indexToDel);
    if(indexToDel < n-1) b3.erase(b3.begin() + indexToDel + 1);
    cout << (makesGood(b1) || makesGood(b2) || makesGood(b3) ? "YES" : "NO") << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("gcd.in","r",stdin);
    int t; cin >> t;
    while(t--){
        // cout << 12 - t << "---" << endl;
        solve();
    }
    return 0;
}