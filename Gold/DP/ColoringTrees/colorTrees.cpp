#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("colortrees.in","r",stdin);
    int N, M, K; cin >> N >> M >> K;
    vector<int> c(N+1);
    for(int i = 1; i <= N;i++){
        cin >> c[i];
    }
    vector<vector<ll>> cost(N+1, vector<ll>(M+1));
    for(int i = 1; i <= N;i++){
        for(int j = 1; j <= M;j++){
            cin >> cost[i][j];
        }
    }

    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(K+1, vector<ll>(M+1, INF)));
    if(c[1] == 1){
        for(int i = 1; i <= M;i++){
            dp[1][1][i] = cost[1][i];
        }
    }else{
        dp[1][1][c[1]] = 0;
    }
    for(int i = 2; i <=N;i++){
        for(int j = 1; j <= K;j++){
            if(c[i] == 0){
                for(int a = 1; a <= M;a++){
                    dp[i][j][a] = min(dp[i][j][a], dp[i-1][j][a] + cost[i][a]);
                    for(int  b = 1; b <= M;b++){
                        if(b != a) dp[i][j][a] = min(dp[i][j][a], dp[i-1][j-1][b] + cost[i][a]);
                    }
                }
            }else{
                dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i-1][j][c[i]]);
                for(int b = 1; b <= M;b++){
                    if(b != c[i]) dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i-1][j-1][b]);
                }
            }
        }
    }
    ll ans = INF;
    for(int i = 1; i <= M;i++){
        ans = min(ans, dp[N][K][i]);
    }
    if(ans >= INF){
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}