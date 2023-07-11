#include <bits/stdc++.h>
#define ll long long

using namespace std; 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("bookShop.in","r",stdin); 
    int n, x; cin >> n >> x;
    vector<int> pages(n), prices(n);

    for(int i = 0; i < n;i++){
        cin >> prices[i];
    }
    for(int i = 0; i < n;i++){
        cin >> pages[i];
    }

    // dp[i][j] is most pages from  i books with at most j spent
    vector<vector<int>> dp(n+1, vector<int>(x+1));
    for(int i = 1; i <= n;i++){
        int curr_cost = prices[i - 1];
		int curr_pages = pages[i - 1];
        for(int j = 1; j <= x;j++){
            dp[i][j] = dp[i-1][j];
            if(curr_cost <= j){
                dp[i][j] = max(dp[i][j], dp[i-1][j-curr_cost] + curr_pages);
            }
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}