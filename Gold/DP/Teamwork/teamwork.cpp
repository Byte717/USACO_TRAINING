#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;
/*
dp[i] = max skill for cows up to i
 for each cow, check the last k cows to make groups
dp[i] = max(dp[i], or skill of adding this cow to las team + all previous sums)
the previous sums are the max*numcows, aka cur*(i-j+1)
dp[j-1] = sum previous cows
*/

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
                dp[i] = max(dp[i], cur*(i-j+1));
            }
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}