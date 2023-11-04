#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

struct PT{
    int x, y; 
};
ll dist(const PT &a, const PT &b) {

	int x = (a.x - b.x);

	int y = (a.y - b.y);


	return (x * x) + (y * y);

}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int h, g; cin >> h >> g;
    vector<PT> hol(h),gur(g);
    for(auto & [x,y] : hol){
        cin >> x >> y;
    }
    for(auto &[x,y] : gur){
        cin >> x >> y;
    }
    vector<vector<vector<ll>>> dp(h+1, vector<vector<ll>>(g+1,vector<ll>(2,INF)));
    dp[1][0][0] = 0;
    for(int i = 0; i <= h;i++){
        for(int j = 0; j <=g;j++){
            if(i > 1){
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][0], dist(hol[i-1], hol[i-2])); // cost to go to holstein next
            }
            if(j > 1){
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1], dist(gur[i-1], gur[i-2])); // Cost to go to gurnsey next
            }
            if(i > 0 && j > 0){
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][1] + dist(hol[i-1], gur[j-1])); // switch from holstein to gurnsey
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][0] + dist(hol[i-1], gur[j-1])); // switch from gurnsey to holstein
            }
        }
    }
    cout << dp[h][g][0] << endl;
    return 0;
}