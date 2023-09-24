#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

/*
What I learned Left Out:
    - think of the base case of a problem that invalidates a specific conditon

*/

vector<vector<int>> grid;
int num(int i1,int j1,int i2,int j2, int b){
    int ans = 0;
    for(int i = i1; i <=i2;i++){
        for(int j = j1;j <=j2;j++){
            if(grid[i][j] == b){
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("leftout.in","r",stdin);
    freopen("leftout.out","w",stdout);
    int n; cin >> n;
    grid = vector<vector<int>>(n,vector<int>(n));
    for(int i = 0; i < n;i++){
        string s; cin >> s;
        for(int j = 0; j < n;j++){
            grid[i][j] = (s[j] == 'L');
        }
    }
    for(int i = 1; i < n;i++){
        grid[i][0] = grid[i][0] ^ grid[i][1];
        for(int j = 1; j < n;j++){
            grid[i][j] = grid[i][j] ^ grid[0][j]  ^ grid[i][0];
        }
    }

    if(num(1,1,n-1,n-1, 0) == 0){
        cout << 1 << ' ' << 1 << endl;
        return 0;
    }
    if(num(1,1,n-1,n-1,1) == n-1){
        for(int j = 1; j < n;j++){
            if(num(1,j,n-1,j,1) == n-1){
                cout << 1 << ' ' << j + 1 << endl;
                return 0;
            }
        }
        for(int j = 1; j < n;j++){
            if(num(j,1,j,n-1,1) == n-1){
                cout << j + 1 << " " << 1 << endl;
                return 0;
            }
        }
    }
    if(num(1,1,n-1,n-1,1) != 1){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 1; i < n;i++){
        for(int j = 1; j < n;j++){
            if(grid[i][j] == 1){
                cout << i + 1 << ' ' << j + 1 << endl;
            }
        }
    }
    return 0;
}