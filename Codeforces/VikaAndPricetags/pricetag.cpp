// #include <bits/stdc++.h>
// #define INF 1e18
// #define MOD 1e9+7
// #define all(x) begin(x),end(x)
// #define rall(x) x.rbegin(), x.rend()

// typedef long long ll;

// using namespace std;

// const int dirX[] = {-1, 0, 1, 0};
// const int dirY[] = {0, 1, 0, -1};

// int LOG2(int n){
//     int ret = 0; 
//     while((1<<(ret+1)) <= n){ret++;}
//     return ret;
// }


// void solve(){
//     int n; cin >> n;
//     vector<int> a(n), b(n);
//     for(int i = 0; i < n;i++){
//         cin >> a[i];
//     }
//     for(int i = 0; i < n;i++){
//         cin >> b[i];
//     }
    
// }

// int main(){
//     cin.tie(0)->sync_with_stdio(0);
//     freopen("","r",stdin);
//     int t; cin >> t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }
#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int gcd(int a, int b) {
    if (a == 0) {
        return 0;
    }
    if (b == 0) {
        return 1;
    }
    if (a >= b) {
        int r = a % b;
        int k = a / b;
        if (k % 2 == 1) {
            return gcd(b, r) + k + k / 2;
        } else {
            return gcd(r, b) + k + k / 2;
        }
    }
    return 1 + gcd(b, abs(a - b));
}
 
int calc(int a, int b) {
    if (a == 0) {
        return 0;
    }
    if (b == 0) {
        return 1;
    }
    return 1 + calc(b, abs(a - b));
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        set<int> cnt;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0 && b[i] == 0) {
                continue;
            }
            cnt.insert(gcd(a[i], b[i]) % 3);
        }
        if (cnt.size() <= 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}