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
    ll n, m, q; cin >> n >> m >> q;

    vector<pair<ll,int>> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    vector<pair<ll,int>> queries(q);
    for(int i = 0; i < n;i++){
        cin >> queries[i].first;
        queries[i].second = i;
    }
    vector<ll> ans(q);
    sort(all(queries));
    
    return 0;
}