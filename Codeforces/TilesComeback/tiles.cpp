#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("tiles.in","r",stdin);
    int t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        ll a[n];
        for(int i = 0; i < n;i++){
            cin >> a[i];
        }
        ll last = n-1;
        ll count = 0;
        for(int i = 0; i < n;i++){
            if(a[i] == a[0]) count++;
            if(count == k){
                last = i;
                break;
            }
        }
        if(count < k){
            cout << "NO" << endl;
            continue;
        }else{
            if(a[0] == a[n-1]){
                cout << "YES" << endl;
                continue;
            }
        }
        count = 0;
        for(int i = n-1; i >last;i--){
            if(a[i] == a[n-1])count++;
        }
        if(count >= k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}