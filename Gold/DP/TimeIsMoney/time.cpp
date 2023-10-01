#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

const int MXDays = 1000;
/*
solution: let dp[i][j] = the max money earned if she is on day i with city j
its basically a max dp but you need to traverse to other nodes via iteration..
so dp[i][j] = max(dp of adj node on next day, or dp of current node + profit right now)


*/
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("time.in","r",stdin);
    freopen("time.out","w",stdout);
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> earn(n);
    for(int i = 0; i < n;i++){
        cin >> earn[i];
    }
    vector<vector<int>> adj(n);
    for(int i = 0; i < m;i++){
        int a,b; cin >> a >> b;
        adj[--a].push_back(--b);

    }
    vector<vector<int>> dp(MXDays+1, vector<int>(n,-1));
    dp[0][0] = 0;

    int ans = 0; 
    for(int d = 0; d < MXDays;d++){
        for(int i = 0; i < n;i++){
            if(dp[d][i] != -1){
                for(auto x : adj[i]){
                    dp[d+1][x] = max(dp[d+1][x], dp[d][i] + earn[x]);
                }
            
            }
        }
        ans = max(ans, (dp[d][0] - (c*d*d)));
    }
    cout << ans << endl;
    return 0;
}