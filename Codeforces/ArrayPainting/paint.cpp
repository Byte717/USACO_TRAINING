#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;
/*
initial thoughts: use dp;
dp[i] = minimum coins needed to paint the first i numbers red
dp[i] = min(dp[i-1]+1, if(a[i-1] != 0) dp[i-1]);
but this doesn't work since the painting isn't supposed to be sequential
*/

/*
actual solution: there are segments that you can paint using 1 coin
- these segments have no 0's and have 2s or 1s
-use greedy to identify and count these segments


What i learned Array Painting:
- when counting a solution, think of how you can earn just 1 of something
- like in this problem, how can you use 1 coin to maximize numbers painted

*/

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("paint.in","r",stdin);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    int ans = 0;
    int left = 0;
    while(left < n){
        int right = left + 1;
        bool hasTwo = (a[left] == 2), hasZero = false;
        while(right < n){
            if(right - 1 > left && a[right-1] == 0){
                hasZero = true;
            }
            if(a[right] == 2){
                hasTwo = true;
            }
            bool good = (!hasZero) && (hasTwo || a[left] != 0 || a[right] != 0);
            if(!good){
                break;
            }
            right++;
        }
        left = right;
        ans++;
    }
    cout << ans << endl;
    return 0;
}