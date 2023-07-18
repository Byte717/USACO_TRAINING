#include <bits/stdc++.h>
#define ll long long

using namespace std; 
const int MAXN = 1e5;

int dp[MAXN][21][3];
int choice[MAXN];
int n,k;



int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("hps.in","r",stdin);
    cin >> n >> k;
    for(int i = 0; i < n;i++){
       char a;
       cin >> a;
       if(a == 'H') choice[i] = 0;
       else if(a == 'P') choice[i] = 1;
       else choice[i] = 2;
    }

    int ans = 0;

    for(int i = 0; i < n;i++){
        for(int j = 0; j <= k;j++){
            for(int m = 0; m < 3;m++){
                if(m == choice[i]) dp[i][j][k]++;

                dp[i+1][j+1][0] = max(dp[i+1][j+1][0], dp[i][j][k]); // next move switches to this element
                dp[i+1][j+1][1] = max(dp[i+1][j+1][1], dp[i][j][m]);
                dp[i+1][j+1][2] = max(dp[i+1][j+1][2], dp[i][j][m]);

                dp[i+1][j][m] = max(dp[i+1][j][m], dp[i][j][m]);
            }
        }
    }

    int MX = max(dp[n-1][k][0], max(dp[n-1][k][1], dp[n-1][k][2]));
    cout << MX << endl;

    return 0;
}