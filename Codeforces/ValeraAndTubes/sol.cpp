#undef NDEBUG
#ifdef gridnevvvit
#define _GLIBCXX_DEBUG
#endif

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <string>
#include <deque>
#include <bitset>
#include <algorithm>
#include <utility>
                  
#include <functional>
#include <limits>
#include <numeric>
#include <complex>

#include <cassert>
#include <cmath>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>   

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int,int> pt;
typedef pair<ld, ld> ptd;
typedef unsigned long long uli;

#define pb push_back
#define mp make_pair
#define mset(a, val) memset(a, val, sizeof (a))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ft first
#define sc second
#define sz(a) int((a).size())
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
template<typename T> inline string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }
template<typename T> inline int hasBit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }
template<typename X, typename T>inline ostream& operator<< (ostream& out, const pair<T, X>& p) { return out << '(' << p.ft << ", " << p.sc << ')'; }

inline int nextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
inline li nextInt64() { li x; if (scanf("%I64d", &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define ford(i, n) for(int i = int(n - 1); i >= 0; i--)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

const int INF = int(1e9);
const li INF64 = li(INF) * li(INF);
const ld EPS = 1e-9;
const ld PI = ld(3.1415926535897932384626433832795);

int n, m, k;

inline bool read() {
 	n = nextInt();
 	m = nextInt();
 	k = nextInt();
 	return true;
}
              
inline void solve() {
        if (n == 3 && m == 3 && k == 3) {
             forn(it, 3) {
                   cout << 3;
                   forn(i, 3) 
                         cout << ' ' << it + 1 << ' ' << i + 1; 
                   puts("");  
             }
             return;
        }
	vector < pt > path;

	int x = 0, y = 0, dir = 1;

	path.pb(mp(x + 1, y + 1));

	while (true) {

		y += dir;

		if (y == m) dir *= -1, y = m - 1, x ++;

		if (y == -1) dir *= -1, y = 0, x++;

		if (x == n) break;

		path.pb(mp(x + 1, y + 1));	
        }

	forn(i, k - 1) {
		printf("%d", 2);
		printf(" %d %d", path[2 * i].ft, path[2 * i].sc);
		printf(" %d %d\n", path[2 * i + 1].ft, path[2 * i + 1].sc);
	}	

	printf("%d", sz(path) - 2 * (k - 1));
	for(int i = 2 * (k - 1); i < sz(path); i++) {
	 	printf(" %d %d", path[i].ft, path[i].sc);
	}
        puts("");

}

int main() 
{
 	assert(read());
	solve();


} 