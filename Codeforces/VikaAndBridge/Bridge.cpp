#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> c(n);
    for(int i = 0; i < n;i++){
        cin >> c[i];
        c[i]--;
    }
    vector<int> lastFound(k,-1);
    vector<int> maxGap(k), maxGap2(k);
    for(int i = 0; i < n;i++){
        int currentGap = i - lastFound[c[i]]; 
        if(currentGap > maxGap[c[i]]){
            maxGap2[c[i]] = maxGap[c[i]];
            maxGap[c[i]] = currentGap;
        }else if(currentGap > maxGap2[c[i]]){
            maxGap2[c[i]] = currentGap;
        }
        lastFound[c[i]] = i;
    }
    for(int i = 0; i < k;i++){
        int lastGap = n - lastFound[i];
        if(lastGap > maxGap[i]){
            maxGap2[i] = maxGap[i];
            maxGap[i] = lastGap;
        }else if(lastGap > maxGap2[i]){
            maxGap2[i] = lastGap;
        }
    }
    int ans = 1e9;
    for(int i = 0; i < k;i++){
        ans = min(ans, max((maxGap[i]+1)/2, maxGap2[i]));

    }
    cout << ans-1 << endl;
}



int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("bridge.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}