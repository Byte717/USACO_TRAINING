#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

// #define debug

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef debug
        freopen("flipGame.in","r",stdin);
    #endif
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    if(n == 1){
        if(a[0] == 1){
            cout << 0 << endl;
        }else{
            cout << 1 << endl;
        }
        return 0;
    }
    int MX = -1;
    for(int i = 0; i < n-1; i++){
        for(int j = i; j < n;j++){
            vector<int> copy = a;
            for(int k = i; k <= j;k++){
                if(copy[k] == 1){
                    copy[k] = 0;
                }else{
                    copy[k] = 1;
                }
            }
            int cnt = 0;
            for(int k = 0; k < n;k++){
                cnt += (copy[k] == 1 ? 1 : 0);
            }
            if(cnt > MX){
                MX = cnt;
                // cout << i << ' ' << j << endl;
            }
        }
    }
    cout << MX << endl;
    return 0;
}