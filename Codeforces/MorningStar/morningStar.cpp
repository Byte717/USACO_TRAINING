#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

/*
sol:NS will have the same x, EW will have the same y;
the diagonals can be expressed as y= x and y = -x
so x-y and x+y;
so store the count of each x, y, x+y, x-y in a map
then the answer is the number of things on the same line *( that num - 1)
*/


void solve(){
    int n; cin >> n;
    map<int,int> NS, EW, NESW, NWSE;
    for(int i = 0; i < n;i++){
        int x, y; cin >> x >> y;
        NS[x]++;
        EW[y]++;
        NESW[x-y]++;
        NWSE[x+y]++;
    }
    int ans = 0;
    for(auto &[x,y] : NS){
        ans+=y*(y-1);
    }
    for(auto &[x,y] : EW){
        ans += y*(y-1);
    }
    for(auto &[x,y] : NESW){
        ans += y *(y-1);
    }
    for(auto &[x,y] : NWSE){
        ans += y*(y-1);
    }
    cout << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("morn.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}