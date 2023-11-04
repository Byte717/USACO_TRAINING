#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;



int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("segment.in","r",stdin);
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    vector<bool> increasing(n,false);
    for(int i = 2; i < n;i++){
        if(a[i] == a[i-1] + a[i-2]){
            increasing[i] = true;
        }
    }
    int MX = 0;
    int start = -1;
    for(int i = 0; i < n;i++){
        if(increasing[i] && start == -1){
            start = i;
        }else if(!increasing[i] && start != -1){
            MX = max(MX, (i-1)-start +1);
            start = -1;
        }
    }
    if(start != -1){
        MX = max(MX,(n-1)-start+1);
    }
    cout << MX + 2 << endl;
    return 0;
}