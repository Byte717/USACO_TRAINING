#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("wolves.in","r",stdin);
    int n, m; cin >> n >> m;
    vector<pair<int,int>> wolves;
    vector<vector<bool>> isPig(n,vector<bool>(m,false));
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            char x; cin >> x;
            if(x == 'P'){
                isPig[i][j] = 1;
            }else if(x == 'W'){
                wolves.push_back({i,j});
            }
        }
    }
    int ans = 0;
    for(auto &[x,y] : wolves){
        for(int i = 0; i < 4;i++){
            int newX = x + dirX[i], newY = y + dirY[i];
            if(newX >= 0 && newX < n && newY >= 0 && newY < m){
                if(isPig[newX][newY]){
                    isPig[newX][newY] = false;
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}