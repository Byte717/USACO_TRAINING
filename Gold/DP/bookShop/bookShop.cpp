#include <bits/stdc++.h>
#define ll long long

using namespace std; 

int n, x;
vector<int> dp;
vector<int> pages, prices;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("bookShop.in","r",stdin);
    cin >> n >> x; 
    dp = vector<int>(x+1, 0); // dp[i] = max Pages for i money
    pages = vector<int>(n); prices = vector<int>(n);

    for(int i = 0; i < n;i++){
        cin >> prices[i];
    }

    for(int j = 0; j < n;j++){
        cin >> pages[j];
    }
    for(int i = 0; i < n;i++){
        dp[prices[i]] = pages[i];
    }
    for(int i = 0; i <= x;i++){
        for(int j = 0; j < n;j++){
            if(i-prices[j] >= 0) dp[i] = max(dp[i], dp[i-prices[j]] + pages[j]);
        }
    }
    cout << dp[x] << endl;
    return 0;
}