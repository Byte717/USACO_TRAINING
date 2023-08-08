#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;
/*
solution: if you number the rows and columns such as
1 2
3 4

that works if m is not prime

otherwise, put the first m/2 rows on the even positions,
and the last m/2 rows in the odd positions

this makes the grid have multiples of m as the differences

*/

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n;++i){
        for(int j = 0; j < m;++j){
            if(i % 2 == 0){
                // current row is even
                cout << (n/2 + i/2) + m + j + 1 << ' ';
            }else{
                cout << (i/2) * m + j + 1 << ' ';
            }
        }
        cout << endl;
    }
    // cout << endl;
}



int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("noPrime.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}