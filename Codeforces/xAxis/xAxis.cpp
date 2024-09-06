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
#define LOCAL

#ifndef debug
    #pragma GCC optimize("O3","unroll-loops")
    #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#endif

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

// https://codeforces.com/problemset/problem/1986/A

void solve(){
    int x1, x2, x3; cin >> x1 >> x2 >> x3;
    int point = (int)((x1+x2+x3)/(3));
    cout << min(abs(point-x1) + abs(point-x2) + abs(point-x3), min(abs(x1-x2)+abs(x1-x3), min(abs(x1-x2)+abs(x2-x3), abs(x1-x3)+abs(x2-x3)))) << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("xAxis.in","r",stdin);
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