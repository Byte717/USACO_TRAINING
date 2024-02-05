#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

void solve(){
    int n; cin >> n;
    vector<int> L(n), R(n), C(n);
    vector<pair<ll,ll>> events;
    for(int i = 0; i < n;i++){
        cin >> L[i];
        events.push_back({L[i], 0});
    }
    for(int i = 0; i < n;i++){
        cin >> R[i];
        events.push_back({R[i], 1});
    }
    for(int i = 0; i < n;i++){
        cin >> C[i];
    }
    sort(all(events));
    sort(C.begin(), C.end());
    vector<ll> st, lengths = {0};
    for(auto [pos, type] : events){
        if(type == 0){
            st.push_back(pos);
        }else{
            lengths.push_back(pos - st.back());
            st.pop_back();;
        }
    }
    sort(lengths.begin() + 1, lengths.end());
    reverse(lengths.begin() + 1, lengths.end());

    ll ans = 0;
    for(ll i = 0; i <= n;i++){
        ans += lengths[i]*C[i-1];
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