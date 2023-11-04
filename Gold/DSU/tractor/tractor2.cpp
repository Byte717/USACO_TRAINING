#include <bits/stdc++.h>
// FloodFill solution
using namespace std; 

int n, half;
int globalCost;
vector<vector<int>> grid;
vector<vector<bool>> visited;

// int floodfill(int i, int j){
//     if(i < 0 || i >= n || j < 0 || j >= n) return 0;
//     if(visited[i][j]){
//         return 0;
//     }
//     visited[i][j] = true;
//     int count = 1;
//     if(i > 0){
//         if(abs(grid[i-1][j] - grid[i][j]) <= globalCost){
//             count += floodfill(i-1,j);
//         }
//     }
//     if(j > 0){
//         if(abs(grid[i][j-1] - grid[i][j]) <= globalCost){
//             count += floodfill(i,j-1);
//         }
//     }
//     if(i < n){
//         if(abs(grid[i+1][j] - grid[i][j]) <= globalCost){
//             count += floodfill(i+1,j);
//         }
//     }
//     if(j < n){
//         if(abs(grid[i][j+1] - grid[i][j]) <= globalCost){
//             count += floodfill(i,j+1);
//         }
//     }
//     return count;
// }

int floodfill(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n) return 0;
    if (visited[i][j]) return 0;
    visited[i][j] = true;
    int count = 1;
    if (i > 0 && abs(grid[i - 1][j] - grid[i][j]) <= globalCost) {
        count += floodfill(i - 1, j);
    }
    if (j > 0 && abs(grid[i][j - 1] - grid[i][j]) <= globalCost) {
        count += floodfill(i, j - 1);
    }
    if (i < n - 1 && abs(grid[i + 1][j] - grid[i][j]) <= globalCost) {
        count += floodfill(i + 1, j);
    }
    if (j < n - 1 && abs(grid[i][j + 1] - grid[i][j]) <= globalCost) {
        count += floodfill(i, j + 1);
    }
    return count;
}

bool works(int mid){
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            visited[i][j] = false;
        }
    }
    globalCost = mid;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            if(!visited[i][j]){
                int res = floodfill(i,j);
                // cout << res << endl; 
                if(res >= half){
                    return true;
                }
            }
        }
    }
    return false;

}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("tractor.in","r",stdin);
    freopen("tractor.out","w",stdout);
    cin >> n;
    grid = vector<vector<int>>(n,vector<int>(n));
    visited = vector<vector<bool>>(n,vector<bool>(n,false));
    half = (int)ceil(n*n/2);

    for(int i = 0;i < n;i++){
        for(int j = 0; j < n;j++){
            cin >> grid[i][j];
        }
    }

    int low = 0, high = 1e6, mid, ans;
    while(low <= high){
        mid = low + (high-low)/2;

        if(works(mid)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}