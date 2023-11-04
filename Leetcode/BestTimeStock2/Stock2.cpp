#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

int maxProfit(vector<int>& prices) {
    int MXProfit = 0;
    for(int i = 1; i < prices.size(); i++) {
        if(prices[i] > prices[i-1]){
            MXProfit += prices[i] - prices[i-1];
        }
    }
    return MXProfit;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    return 0;
}