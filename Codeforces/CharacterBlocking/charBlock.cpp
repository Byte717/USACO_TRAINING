#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int bad = 0; 
    for(int i = 0; i < n;i++){
        if(s1[i] != s2[i]){
            bad++;
        }
    }
    int t, q; cin >> t >> q;
    queue<pair<int,int>> unblock;
    while(q--)
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}