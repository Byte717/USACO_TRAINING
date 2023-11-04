#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("queries.in","r",stdin);
    string s; cin >> s;
    int n = s.size();
    vector<bool> satisfied(n,false);
    for(int i = 0; i < n-1;i++){
        satisfied[i] = (s[i] == s[i+1] ? true: false);
    }
    vector<int> pref(n+1,0);
    for(int i = 0; i < n;i++){
        pref[i+1] = pref[i] + (satisfied[i] ? 1 : 0); 
    }
    int m; cin >> m;
    while(m--){
        int l, r; cin >> l >> r;
        cout << pref[r-1] - pref[l-1] << endl;
    }
    return 0;
}