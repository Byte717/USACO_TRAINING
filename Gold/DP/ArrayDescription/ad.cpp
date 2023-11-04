#include <bits/stdc++.h>
#define ll long long

using namespace std; 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("ad.in","r",stdin);
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(m+1,0));
    if(values[0] != 0){
        dp[0][values[0]] = 1;
    }else{
        for(int i = 1; i <= m;i++){
            dp[0][i] = 1;
        }
    }
    for(int i = 0; i < n;i++){
        if(values[i] == 0){
            for(int j = 1; j <= m;j++){
                if(j-1 >= 1) dp[i][j] += dp[i-1][j-1];
                if(j+1 <= m) dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= 1e9+7;
            }
        }else{
            dp[i][arr[i]] += dp[i - 1][arr[i]];
			if (arr[i] - 1 > 0) dp[i][arr[i]] += dp[i - 1][arr[i] - 1];
			if (arr[i] + 1 <= m) dp[i][arr[i]] += dp[i - 1][arr[i] + 1];
        }
    }
    	ll ans = 0;
	for (int i = 1; i <= m; i++) {
		ans += dp[n - 1][i];
		ans %= 1e9+7;
	}
    return 0;
}