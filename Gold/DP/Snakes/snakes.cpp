#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


/*
dp[i][j][k] = min loss with ith group, j current size, k switches
dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k] + (j-a[i]), dp[i][a[i]][k+1]) take last, size, change size

dp[n][max(a[i])][k] = too slow

*/

void badSol(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(1e6+1, vector<int>(k+1, INF))); 
    dp[0][a[0]][0] = 0;
    for(int i = 0; i <= n;i++){
        for(int j = 0; j < dp[i].size();j++){
            for(int chg = 0; chg <= k;chg++){
                // 2 cases, take prev + loss, or change size
                if(i){

                }
                if(j){

                }

                if(i && j){
                    
                }

            }
        }
    }
}

/*
make dp[i][j] = the min loss with catching first i snakes with j resizes
*/

void goodSol(){
    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    int largest = -1;
    int spaceUsed = 0;
    for(int i = 1; i <= n;i++){
        largest = max(largest, a[i]);
        dp[i][0] = largest*i; // part of the bigest net.
        for(int j = 1; j <= k;j++){
            dp[i][j] = INF;
            int net = a[i];
            for(int c = i-1; c >= 0; c--){
                dp[i][j] = min(dp[i][j], dp[c][j-1] + net*(i-c));
                net = max(net, a[c]);
            }
        }
        spaceUsed += a[i];
    } 
    cout << dp[n][k] - spaceUsed << endl;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    return 0;
}