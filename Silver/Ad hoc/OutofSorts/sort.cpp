#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

struct Entry{
    int idx;
    int val;
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;
    vector<Entry> entries(n);
    for(int i = 0; i < n;i++){
        cin >> entries[i].val;
        entries[i].idx = i;
    }
    sort(all(entries), [](Entry a, Entry b){
        if(a.val == b.val) return a.idx < b.idx;
        return a.val < b.val;
    });
    int ans = 0;
    for(int j = 0; j < n;j++){
        ans = max(ans, entries[j].idx - j);
    }
    cout << ans + 1 << endl;
    return 0;
}