#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

const int dX[4] = {-1, 0, 1, 0};
const int dY[4] = {0, 1, 0, -1};
struct Cell{
    bool wall;
    int numVis;
};
struct Candidate{
    int i,j;
    int vis;
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n,m, k;
    vector<vector<char>> grid(n,vector<Cell>(m));
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            char x; cin >> x;
            if(x == '#'){
                grid[i][j] = Cell{true, 0};
            }else{
                grid[i][j] = Cell{false,0};
            }
        }
    }
    function<bool(int,int)> inBound = [&](int i,int j){
        return !(i < 0 || i >= n || j < 0 || j >= m);
    };
    function<void(int,int)> floodfill = [&](int i, int j){
        if(!inBound(i,j)){
            return;
        }
    };

    
    return 0;
}