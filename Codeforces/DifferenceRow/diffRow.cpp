#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(all(a));
    swap(a[0],a[n-1]);
    for(int i = 0; i < n;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}