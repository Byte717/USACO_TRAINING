#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;
class Coord{
    public: 
        int x, y;
};

ll dist(Coord a, Coord b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int h, g; cin >> h >> g;
    vector<Coord> holsteins(h), guernseys(g);
    for(auto &[x,y] : holsteins) cin >> x >> y;
    for(auto &[x,y] : guernseys) cin >> x >> y;
    // dp[i][j][k]
    vector<vector<vector<ll>>> dp(h+1, vector<vector<ll>>(g+1, vector<ll>(2,INF)));
    dp[1][0][0] = 0;
    for(int i = 0; i <= h;i++){
        for(int j = 0; j <= g;j++){
            if(i > 1){
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][0] + dist(holsteins[i-2], holsteins[i-1]));
            }
            if(j > 1){
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1] + dis(guernseys[j-2], guernseys[j-1]));
            }
            if(i > 0 && j > 0){
                dp[i][j][0] = min(dp[i][j][0], dp[i][j][1] + dist(holsteins[i-1], guernseys[j-1]));
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][0] + dist(holsteins[i-1],guernseys[j-1]));
            }
        }
    }
    cout << dp[h][g][0] << endl;
    return 0;
}