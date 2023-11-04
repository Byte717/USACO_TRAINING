#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    vector<int> dp(n,-1);
    for(int i = 0; i < n;i++){
        int cur = arr[i];
        for(int j = i; j >= (i - k + 1) && ~j;j--){
            cur = max(cur, skill[j]);
            if(j > 0){
                dp[i] = max(dp[i], dp[j-1] + (cur*(i-j-1)));
            }else{

            }
        }

    }
    return 0;
}