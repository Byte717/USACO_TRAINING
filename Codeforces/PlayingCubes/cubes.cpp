#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int n, m; cin >> n >> m;
    cout << max(n,m)-1 << ' ' << min(n,m) << endl;
    return 0;
}