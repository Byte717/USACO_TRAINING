#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

// #define debug

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef debug
        freopen("freeCash.in","r",stdin);
    #endif
    int n; cin >> n;
    vector<vector<int>> cnt(24, vector<int>(60,0));
    for(int i = 0; i < n;i++){
        int a, b; cin >> a >> b;
        cnt[a][b]++;
    }
    int mx = 0;
    for(int i = 0; i < cnt.size();i++){
        for(int j = 0; j < cnt[i].size();j++){
            mx = max(mx, cnt[i][j]);
        }
    }
    cout << mx << endl;
    return 0;
}