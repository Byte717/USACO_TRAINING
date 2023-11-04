#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("stones.in","r",stdin);
    int n; cin >> n;
    vector<ll> stones(n+1);    
    vector<ll> normalPref(n+1,0);
    for(int i = 1; i <= n;i++){
        cin >> stones[i];
        normalPref[i] = stones[i] + normalPref[i-1];
    }
    sort(all(stones));
    vector<ll> sortedPref(n+1,0);
    for(int i = 1; i<=n;i++){
        sortedPref[i] = stones[i] + sortedPref[i-1];
    }

    int m; cin >> m;
    while(m--){
        int type; cin >> type;
        int a,b; cin >> a >> b;
        if(type == 1){
            cout << normalPref[b] - normalPref[a-1] << endl;
        }else{
            cout << sortedPref[b] - sortedPref[a-1] << endl;
        }
    }
    return 0;
}