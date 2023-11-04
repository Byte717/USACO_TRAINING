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
    int n, x; cin >> n >> x;
    vector<int> a(n);
    int low = 0, equal = 0, high = 0;
    for(int i = 0; i < n;i++){
        cin >> a[i];
        if(a[i] == x){
            equal++;
        }
        if(a[i] < x){
            low++;
        }else{
            high++;
        }
    }
    int cnt = 0;
    while(true){
        if(low < (cnt + n + 1)/2 && low + equal >= (cnt + n + 1)/2){
            break;
        }
        equal++;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}