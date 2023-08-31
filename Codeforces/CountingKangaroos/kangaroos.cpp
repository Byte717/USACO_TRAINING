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
        freopen("","r",stdin);
    #endif
    int n; cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n;i++){
        cin >> s[i];
    }
    sort(all(s));
    int pt = n/2;
    int ans = n;
    for(int i = 0; i < n/2;i++){
        for(;;){
            if(s[i]*2 <= s[pt]){
                ans--;
                pt++;
                break;
            }else{
                pt++;
            }
            if(pt == n){
                break;
            }
        }
        if(pt == n){
            break;
        }
    }
    cout << ans << endl;
    return 0;
}