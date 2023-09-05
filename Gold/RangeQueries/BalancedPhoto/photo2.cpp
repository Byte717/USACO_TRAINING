#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
what I learned Balanced Photo:
    - use 2 data structures for asynchronous queries.
    - BIT indexes can represent count arrays for inversion counting


*/



int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("bphoto.in","r",stdin);    
    int n; cin >> n; 
    vector<ll> h(n);
    Tree<ll> right;
    for(int i = 0; i < n;i++){
        cin >> h[i];
        right.insert(h[i]);
    }
    Tree<ll> left;
    ll ans = 0;
    for(auto &i : h){
        right.erase(i);
        int leftGreater = left.size() - left.order_of_key(i);
        int rightGreater = right.size() - right.order_of_key(i);
        left.insert(i);
        if(max(leftGreater,rightGreater) > min(leftGreater,rightGreater)*2) ans++;
    }
    cout << ans << endl;
    return 0;
}