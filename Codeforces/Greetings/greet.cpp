#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll INF = 1e18;
const ll MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<pair<ll,ll>> people(n);
    for(int i = 0; i < n;i++){
        cin >> people[i].second >> people[i].first;
    }
    sort(all(people));
    Tree<ll> st;
    ll ans = 0;
    for(auto& p : people){
        ans += st.size() - st.order_of_key(p.second);
        st.insert(p.second);
    }
    cout << ans << endl;
    
}



int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}