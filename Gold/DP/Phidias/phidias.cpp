#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;
/*
dp[i][j][k] = space used if the [i,j]th square inch belongs to the kth piece

dp[i][j][k] = max(last one ending 1 block before, last one ending 1 block above, the last block ending diagonally up)


*/
void badSol(){
    int w, h; cin >> w >> h;
    int n; cin >> n;
    vector<pair<int,int>> segments(n);

    for(auto &[x,y] : segments){
        cin >> x >> y;
    }
    vector<vector<int>> dp(w+1, vector<int>(h+1,0));
    for(auto &[x,y] : segments){
        dp[x][y] = x*y;
    }

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    return 0;
}