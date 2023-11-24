#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;

    vector<int> heights(n);
    for(int i = 0; i < n;i++){
        cin >> heights[i];
    }
    vector<int> idx(n+1); // idx[i] = the index in which the cow with height i appears
    for(int i = 0;i < n;i++){
        idx[heights[i]] = i;
    }
    ll ans = 0;
    set<int> present;
    for(int cur_h = n; cur_h; cur_h--){
        auto it = present.insert(idx[cur_h]).first;
        if(next(it) != end(present)) ans += *next(it) - *it + 1; // from backwords, if this element isnt at the end, then there is a cow to the right with nothing in between
    }
    cout << ans << endl;
    return 0;
}