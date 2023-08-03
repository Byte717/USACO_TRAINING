#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;



void fasterLis(int n, vector<ll> a){
    vector<int> dp;
    for(int i = 0; i < n;i++){
        int pos = lower_bound(all(dp), a[i]) - dp.begin();
        if(pos == dp.size()){
            dp.push_back(a[i]);
        }else{
            dp[pos] = a[i];
        }
    }
    cout << dp.size() << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;
    vector<ll> x(n);
    for(int i = 0; i < n;i++){
        cin >> x[i];
    }
    int LIS = 0;
    vector<int> dp(n, 1);
    for(int i = 0; i < n;i++){
        for(int j = 0; j < i;j++){
            if(x[j] < x[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int MX = -1;
    for(int i = 0; i < n;i++){
        MX = max(MX, dp[i]);
    }
    cout << MX << endl;
    return 0;
}