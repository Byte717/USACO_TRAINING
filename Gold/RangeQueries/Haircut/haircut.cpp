#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*
solution:

What I learned Haircut:
    - The number of inversions is a measure of how sorted an array


*/
/** @return the sum between a and b. */
int sum(vector<ll> &segtree, int a, int b) {
	int c = segtree.size() / 2;
	a += c;
	b += c;
	int s = 0;
	while (a <= b) {
		if (a % 2) s += segtree[a++];
		if (!(b % 2)) s += segtree[b--];
		a /= 2;
		b /= 2;
	}
	return s;
}

/** Increase the element at k by x in the segment tree. */
void add(vector<ll> &segtree, int k, ll x) {
	int c = segtree.size() / 2;
	k += c;
	segtree[k] += x;
	for (k /= 2; k >= 1; k /= 2) {
		segtree[k] = segtree[2 * k] + segtree[2 * k + 1];
	}
}

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret)) <= n+1){ret++;}
    return ret;
}

void setSolution(){
    int n; cin >> n;
    vector<ll> inp(n);
    vector<ll> ans(n);
    Tree<ll> set;
    for(int i = 0; i < n;i++){
        int a; cin >> a;
        ans[i] = i - set.order_of_key(a);
        set.insert(a);
        inp.push_back(a);
    }
    for(int i = 0; i < n;i++){
        
    }
    ll total = 0;
    for(int i = 0; i < n;i++){
        total += ans[i];
        cout << total << endl;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("haircut.in","r",stdin);
    setSolution();
    // int n; cin >> n;
    // int log = LOG2(n);
    // log = 1 << log;
    // vector<ll> segtree(2*log,0);
    // vector<ll> ans(n+2,0);
    // for(int i = 1; i <= n;i++){
    //     int a; cin >> a;
    //     ans[a+1] += sum(segtree, a+1,n+1);
    //     add(segtree,a,1);
    // }
    // ll total = 0;
    // for(int i = 0; i < n;i++){
    //     total += ans[i];
    //     cout << total << endl;
    // }
    return 0;
}