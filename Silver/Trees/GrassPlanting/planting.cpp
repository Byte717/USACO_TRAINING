#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("planting.in","r",stdin);
    freopen("planting.out","w",stdout);
    int n; cin >> n;
    vector<int> deg(n,0);
    for(int i = 0; i < n-1;i++){
        int x, y; cin >> x >> y;
        x--; y--;
        deg[x]++;
        deg[y]++;
    }
    int MX = -1;
    for(int i = 0; i < n;i++){
        MX = max(MX, deg[i]);
    }
    cout << MX+1 << endl;
    return 0;
}