#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

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

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("bphoto.in","r",stdin);
    int n; cin >> n; 
    vector<ll> h(n);
    for(int i = 0; i < n;i++){
        cin >> h[i];
    }
    vector<ll> copy = h;
    sort(all(copy));
    map<ll,int> compress;
    int cnt = 0;
    for(int i = 0; i < n;i++){
        if(compress.find(copy[i]) == compress.end()){
            compress[copy[i]] = cnt++;
        }
    }
    BIT<ll> right(cnt);
    for(int i = 0; i < n;i++){
        right.add(compress[h[i]], 1);
    }
    BIT<ll> left(cnt);
    ll ans = 0;
    for(int i = 0; i < n;i++){
        int leftGreater = left.pref_sum(cnt) - left.pref_sum(min(compress[h[i]] + 1, cnt));
        int rightGreater = right.pref_sum(cnt) - right.pref_sum(min(compress[h[i]]+1, cnt));
        left.add(compress[h[i]],1);
        // right.set(compress[h[i]],0);
        if(max(leftGreater,rightGreater) > min(leftGreater,rightGreater)*2) ans++;
    }
    cout << ans << endl;
    return 0;
}