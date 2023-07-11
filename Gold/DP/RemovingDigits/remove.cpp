#include <bits/stdc++.h>
#define ll long long

using namespace std; 




int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("remove.in","r",stdin);
    int n; cin >> n;
    vector<int> dp(n+1,1e5);
    for(int i = 0; i <= 9;i++){
        dp[i] = 1;
    }

    for(int i = 10; i <= n;i++){
        int copy = i;
        while(copy > 0){
            dp[i] = min(dp[i-(copy%10)]+1, dp[i]);
            copy /= 10;
        }
    }
    cout << dp[n] << endl;
    return 0;
}