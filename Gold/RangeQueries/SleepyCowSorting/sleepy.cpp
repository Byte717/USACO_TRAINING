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

	void set(int ind, int val) { add(ind, val - arr[ind]); }

    void clear(){
        bit.clear();
        arr.clear();
    }

	void add(int ind, int val) {
		arr[ind] += val;
		ind++;
		for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
	}

	T pref_sum(int ind) {
		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
		return total;
	}
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("sleepy.in","r",stdin);
    int n; cin >> n;
    vector<int> cows(n);
    for(int i = 0; i < n;i++){
        cin >> cows[i];
        cows[i]--;
    }

    BIT<int> sorted(n+1);
    int added = 0;
    for(int i = n-1; i >= 0;i--){
        if(i!=n-1){
            if(cows[i] < cows[i+1]){
                added++;
                sorted.add(cows[i],1);
            }else{
                break;
            }
        }else{
            added++;
            sorted.add(cows[i],1);
        }
    }
    cout << n - added << endl;
    vector<int> ans;
    for(int i = 0; i < n-added; i++){
        sorted.add(cows[i],1);
        ans.push_back(sorted.pref_sum(cows[i]) + ((n-added-i)-1));
    }
    for(int i = 0; i < ans.size();i++){
        cout << ans[i]-1 << ' ';
    }
    cout << endl;

    return 0;
}