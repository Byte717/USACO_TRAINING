#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> maxToRight(n);
    maxToRight[n-1] = prices[n-1];
    for(int i = n-2;i >= 0;i--) {
        maxToRight[i] = max(maxToRight[i+1], prices[i]);
    }
    int MXProfit = 0;
    for(int i = 0; i < n;i++){
        if(maxToRight[i]-prices[i] > 0){
            MXProfit = max(MXProfit,maxToRight[i]-prices[i]);
        }
    }    
    return MXProfit;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    return 0;
}