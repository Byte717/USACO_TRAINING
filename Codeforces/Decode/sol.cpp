#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
 
template<ll M>
struct modint {
 
    static ll _pow(ll n, ll k) {
        ll r = 1;
        for (; k > 0; k >>= 1, n = (n*n)%M)
            if (k&1) r = (r*n)%M;
        return r;
    }
 
    ll v; modint(ll n = 0) : v(n%M) { v += (M&(0-(v<0))); }
    
    friend string to_string(const modint n) { return to_string(n.v); }
    friend istream& operator>>(istream& i, modint& n) { return i >> n.v; }
    friend ostream& operator<<(ostream& o, const modint n) { return o << n.v; }
    template<typename T> explicit operator T() { return T(v); }
 
    friend bool operator==(const modint n, const modint m) { return n.v == m.v; }
    friend bool operator!=(const modint n, const modint m) { return n.v != m.v; }
    friend bool operator<(const modint n, const modint m) { return n.v < m.v; }
    friend bool operator<=(const modint n, const modint m) { return n.v <= m.v; }
    friend bool operator>(const modint n, const modint m) { return n.v > m.v; }
    friend bool operator>=(const modint n, const modint m) { return n.v >= m.v; }
 
    modint& operator+=(const modint n) { v += n.v; v -= (M&(0-(v>=M))); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&(0-(v<0))); return *this; }
    modint& operator*=(const modint n) { v = (v*n.v)%M; return *this; }
    modint& operator/=(const modint n) { v = (v*_pow(n.v, M-2))%M; return *this; }
    friend modint operator+(const modint n, const modint m) { return modint(n) += m; }
    friend modint operator-(const modint n, const modint m) { return modint(n) -= m; }
    friend modint operator*(const modint n, const modint m) { return modint(n) *= m; }
    friend modint operator/(const modint n, const modint m) { return modint(n) /= m; }
    modint& operator++() { return *this += 1; }
    modint& operator--() { return *this -= 1; }
    modint operator++(int) { modint t = *this; return *this += 1, t; }
    modint operator--(int) { modint t = *this; return *this -= 1, t; }
    modint operator+() { return *this; }
    modint operator-() { return modint(0) -= *this; }
 
    modint pow(const ll k) const {
        return k < 0 ? _pow(v, M-1-(-k%(M-1))) : _pow(v, k);
    }
    modint inv() const { return _pow(v, M-2); }
};
 
using mint = modint<int(MOD)>;
 
 
int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int n = s.size();
		vector<int> p(n+1);
		for(int i = 1; i <= n; i++){
			p[i] = p[i-1] + (s[i-1] == '0' ? -1 : 1);
		}
		vector<vector<ll>> sums(2 * n + 1);
		for(int i = 0; i <= n; i++){
			sums[p[i] + n].push_back(i);
		}
		mint ans = 0;
		for(auto& v: sums){
			int N = v.size();
			vector<ll> j_sum(N+1);
			for(int i = N - 1; i >= 0; i--){
				j_sum[i] = j_sum[i+1] + v[i];
			}
			for(int i = 0; i < N - 1; i++){
				ll left = N - i - 1;
				ans += v[i] * n * left;
				ans -= v[i] * j_sum[i+1];
				ans += v[i] * left;
				ans += n * left;
				ans -= j_sum[i+1];
				ans += left;
			}
		}
		cout << ans << "\n";
	}
}