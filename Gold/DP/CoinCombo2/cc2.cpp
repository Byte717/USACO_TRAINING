#include <bits/stdc++.h>
#define ll long long

using namespace std; 
const int MAXN = 1e2 + 1;
int n, x;
int dp[MAXN];
int c[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("cc2.in","r",stdin);
    cin >> n >> x; 
    for(int i = 0; i < n;i++){
        cin >> c[i];
        // dp[c[i]] = 1;
    }
    dp[0] = 1;
    for(int i = 0; i < n;i++){
        for(int j = 1; j <= x;j++){
            if(j-c[i] >= 0) dp[j] += dp[j-c[i]];
        }
    }
    cout << dp[x] << endl;
    return 0;
}