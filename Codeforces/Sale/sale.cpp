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
    int n,m; cin >> n >> m;
    vector<int> tv(n);
    for(int i = 0; i < n;i++){
        cin >> tv[i];
    }
    sort(all(tv));
    int ans = 0;
    for(int i = 0; i < m;i++){
        if(tv[i] < 0){
            ans += tv[i];
        }else{
            break;
        }
    }
    cout << -ans << endl;
    return 0;
}