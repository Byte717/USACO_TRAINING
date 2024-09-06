#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <random>
#include <ratio>
#include <regex>
#include <unordered_map>
#include <unordered_set>
#include <future>
#include <typeinfo>
#include <cassert>
#include <chrono>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define len(x) x.size()

#define debug
// #define LOCAL

#ifndef debug
    #pragma GCC optimize("O3","unroll-loops")
    #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#endif

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


void solve(){
    int n, k; cin >> n >> k;
    k--;
    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];
    int x = find_if(a.begin(), a.end(), [&](int v) { return v > a[k]; }) - a.begin(); // first first cow greater than kth cow
    vector<int> pos(n); iota(pos.begin(), pos.end(), 0);// stores position
    int ans = 0;
    for (int i : {0, x}) {// you can swap with either first cow or the first cow greater than your cow
        if (i == n) {
            continue;
        }
        swap(pos[i], pos[k]);
        vector<int> stt(n);
        for (int j = 1, u = pos[0]; j < n; j++) {
            int v = pos[j];
            u = (a[u] > a[v] ? u : v);
            stt[u]++;
        }
        swap(pos[i], pos[k]);
        ans = max(ans, stt[k]);
    }
    cout << ans << '\n';
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    #ifdef LOCAL
	auto _clock_start = chrono::high_resolution_clock::now();
    #endif
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    #ifdef LOCAL
    cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
        chrono::high_resolution_clock::now()
            - _clock_start).count() << "ms." << endl;
    #endif
    return 0;
}