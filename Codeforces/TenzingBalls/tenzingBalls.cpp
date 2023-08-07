#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

/*
framework:Use dp
IDk how to do this problem
Form:find optimal solution or count solutions
*/

/*
actual solution:    
dp[i] = number of indexes not deleted from 0--i
either we don't delete current element, dp[i-1] + 1
or we find the minimum j such that a[j] = a[i], in that case its dp[j]
store dp[j] for each i in a separate array
*/

/*
What I learned: TenzingBalls
instead of dp[i][j], you can break it into 2 separate arrays to speed up the time
you can use inverse counting, dont count the answer, count n-ans
*/

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    vector<int> dp(n+1), buc(n+1, 1e6); // buc[a[i]] stores the last index where a[i] == a[j]
    dp[0] = 0;
    for(int i = 1;i <= n;i++){
        dp[i] = min(dp[i-1]+1, buc[a[i-1]]);
        buc[a[i-1]] = min(buc[a[i-1]], dp[i-1]);
    }
    cout << n - dp[n] << endl;
}



int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("tenzing.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}