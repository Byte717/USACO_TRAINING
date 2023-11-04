#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
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
    freopen("circlecross.in","r",stdin);
    int n; cin >> n;
    vector<int> a(2*n);
    for(int i = 0; i < 2*n;i++){
        cin >> a[i];
        a[i]--;
    }
    vector<pair<int,int>> order(n,{-1,-1});
    for(int i = 0; i < 2*n;i++){
        if(order[a[i]].first == -1){
            order[a[i]].first = i;
        }else{
            order[a[i]].second = i;
        }
    }
    sort(all(order));
    int ans = 0;
    BIT<int> endT(2*n);
    for(int i = 0; i < n;i++){
        ans += endT.pref_sum(order[i].second) - endT.pref_sum(order[i].first);
        endT.add(order[i].second,1); 
    }
    freopen("circlecross.out","w",stdout);
    cout << ans << endl;
    return 0;
}