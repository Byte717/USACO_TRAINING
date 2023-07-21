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

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    vector<int> lower(n,0), higher(n,0);
    Tree<int> t1;
    for(int i = 0; i < n;i++){
        lower[i] += t1.order_of_key(arr[i]);
        t1.insert(arr[i]);
    }
    Tree<int> t2;
    for(int i = 0; i < n;i++){
        higher[i] += t2.size() - t2.order_of_key(arr[i]);
        t2.insert(arr[i]);
    }
    int ans = 0;
    for(int i = 0; i < n;i++){
        ans += high[i] *low[i];
    }
    cout << ans << endl;
    return 0;
}
