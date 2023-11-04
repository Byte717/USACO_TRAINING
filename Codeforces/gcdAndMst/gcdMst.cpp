#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

// #define debug

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

const int dirX[4] = {-1, 0, 1, 0};
const int dirY[4] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

void solve(){
    int n,x; cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    vector<bool> isConnected(n);
    vector<pair<int,int>> vals;
    for(int i = 0; i < n;i++){
        vals.push_back({a[i],i});
    }
    sort(all(vals));
    ll ans = 0;
    for(auto &[currVal, i] : vals){
        if(currVal >= x){
            break;
        }
        int I = i;
        while(I > 0){
            if(isConnected[I-1]) break;
            if(a[I-1]%currVal == 0){
                isConnected[I-1] = true;
                ans += currVal;
                I--;
            }else{
                break;
            }
        }
        I = i;
        while(I < n-1){
            if(isConnected[I]) break;
             if(a[I+1]%currVal == 0){
                isConnected[I] = true;
                ans += currVal;
                I++;
             }else{
                break;
             }
        }
    }
    for(int i = 0; i < n-1;i++){
        if(isConnected[i]){
            ans += x;
        }
    }
    cout << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef debug
        freopen("","r",stdin);
    #endif
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}