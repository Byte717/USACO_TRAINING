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
    for(int i = 0; i < )
    return 0;
}