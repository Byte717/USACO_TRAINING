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
    freopen("salaries.in","r",stdin);
    int n, q; cin >> n >> q;
    Tree<pair<ll,int>> set;
    vector<ll> salaries(n);
    for(int i = 0; i < n;i++){
        cin >> salaries[i];
        set.insert({salaries[i],i});
    }
    for(int i = 0; i < q;i++){
        char type; cin >> type;
        if(type == '?'){
            int a, b;cin >> a >> b;
            cout << set.order_of_key({b,MOD}) - set.order_of_key({a-1,MOD}) << endl;
        }else{
            int k, x; cin >> k >> x;
            int sal = salaries[k];
            set.erase(set.find({sal,k}));
            set.insert({x,k});
            salaries[k]= x;
        }
    }
    return 0;
}
