#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

int minDistance(string word1, string word2){
    int n = word1.length(), m = word2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,MOD));
    dp[0][0] = 0;
    for(int i = 0; i <= n;i++){
        for(int j = 0; j <= m;j++){
            if(i > 0){
                dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
            }
            if(j > 0){
                dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
            }
            if(i > 0 && j > 0){
                if(word1[i] == word2[j]){
                    dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
                }else{
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
                }
            }
        }
    }
    cout << dp[n][m] << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    return 0;
}