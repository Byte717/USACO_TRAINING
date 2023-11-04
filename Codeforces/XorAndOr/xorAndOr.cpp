#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

/*
what I learned Xor and OR:
    - think of the base cases. not everything has to be a complex algorithm

*/


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("xorAndOr.in","r",stdin);
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    if(n != m){
        cout << "NO" << endl;
        return 0;
    }
    if(n == 1 && m == 1){
        if(a == b){
            cout << "YES" << endl;
            
        }else{
            cout << "NO" << endl;
        }
        return 0;
    }
    if(a == b){
        cout << "YES" << endl;
        return 0;
    }
    bool allZero = true;
    for(int i = 0; i < n;i++){
        if(a[i] == '1'){
            allZero = false;
            break;
        }
    }
    if(allZero){
        cout << "NO" << endl;
        return 0;
    }
    allZero = true;
    for(int i = 0; i < n;i++){
        if(b[i] == '1'){
            allZero = false;
            break;
        }
    }
    if(allZero){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}