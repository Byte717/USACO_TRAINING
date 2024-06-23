#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


template <class T> class BIT {
  private:
	int size;
	vector<T> bit;
	vector<T> arr;

  public:
	BIT(int size) : size(size), bit(size + 1), arr(size) {}

	/** Sets the value at index ind to val. */
	void set(int ind, int val) { add(ind, val - arr[ind]); }

	/** Adds val to the element at index ind. */
	void add(int ind, int val) {
		arr[ind] += val;
		ind++;
		for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
	}

	/** @return The sum of all values in [0, ind]. */
	T pref_sum(int ind) {
		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
		return total;
	}
};

void solve() {
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << "0\n";
        return;
    }

    int mx = *max_element(a.begin() + 1, a.end());
    int mxc = max(a[0] + c, mx);
    int winner = mxc == a[0] + c ? 0 : find(a.begin() + 1, a.end(), mx) - a.begin();
    ll sum = c;
    for (int i = 0; i < n; sum += a[i], ++i) {
        int answer;
        if (i == winner) {
            answer = 0;
        } else if (sum + a[i] >= mx) {
            answer = i;
        } else {
            answer = i + 1;
        }
        cout << answer << " \n"[i == n - 1];
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("elections.in","r",stdin);
    int t; cin >> t;
    while(t--){ // dont work, moving on, same idea as solution however
        solve();
        // int n, c; cin >> n >> c;
        // vector<int> a(n);    
        // BIT<int> pref(n);
        // for(int i = 0; i < n;i++){
        //     cin >> a[i];
        //     pref.set(i, a[i]);
        // }
        // pref.set(0, a[0] + c);
        // a[0] += c;
        // vector<int> ans(n,-1);
        // vector<pair<int,int>> b(n);
        // for(int i = 0; i < n;i++){
        //     b[i] = {a[i],i};
        // }
        // sort(all(b));
        // ans[b[n-1].second] = 0; 
        // for(int i = 0; i < n;i++){
        //     if(ans[i] == 0) continue;
        //     if(i == 0){
        //         ans[i] = (a[i] + a[n-1] > a[n-2] ? 1 : 0);
        //         continue;
        //     }
        //     ans[i] = (a[i] + pref.pref_sum(i) > b[n-1].first ? i : i + 1);
        // }
        // for(int i = 0; i < n;i++){
        //     cout << ans[i] << ' ';
        // }
        // cout << endl;
    }
    return 0;
}