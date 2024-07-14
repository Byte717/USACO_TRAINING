#include "bits/stdc++.h"
 
#define err(x) cerr << "["#x"]  " << (x) << "\n"
#define errv(x) {cerr << "["#x"]  ["; for (const auto& ___ : (x)) cerr << ___ << ", "; cerr << "]\n";}
#define errvn(x, n) {cerr << "["#x"]  ["; for (auto ___ = 0; ___ < (n); ++___) cerr << (x)[___] << ", "; cerr << "]\n";}
#define all(a) a.begin(), a.end()
#define pb push_back
typedef long long ll;
typedef long double ld;
using namespace std;
const int MOD = 1000000007;
mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
 
template<typename T1, typename T2>
inline bool relaxmi(T1 &a, const T2 &b) {
    return a > b ? a = b, true : false;
}
 
template<typename T1, typename T2>
inline bool relaxma(T1 &a, const T2 &b) {
    return a < b ? a = b, true : false;
}
 
double GetTime() { return clock() / (double) CLOCKS_PER_SEC; }
 
/// Actual code starts here
const int N = 100005;
 
int calc(vector<pair<int, int>> &t, int d) {
    int LCM = 0, cnt = 0;
    for (auto [j, c]: t) {
        if (d % j == 0) {
            if (LCM == 0) LCM = j;
            else LCM = lcm(LCM, j);
            cnt += c;
        }
    }
    if (LCM != d) cnt = 0;
    return cnt;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i: v) cin >> i;
    ll LCM = 1;
    int mx = *max_element(all(v));
    for (auto i: v) {
        LCM = lcm(LCM, i);
        if (LCM > mx) {
            cout << n << '\n';
            return;
        }
    }
    map<int, int> cnt;
    for (auto i: v) cnt[i]++;
    vector<pair<int, int>> t;
    for (auto i: cnt)
        t.push_back(i);
    int res = 0;
    for (int i = 1; i * i <= mx; i++) {
        if (mx % i == 0) {
            if (!cnt.contains(i))
                relaxma(res, calc(t, i));
            if (!cnt.contains(mx / i))
                relaxma(res, calc(t, mx / i));
        }
    }
    cout << res << '\n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
}