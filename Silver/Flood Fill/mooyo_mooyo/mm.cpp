#include <bits/stdc++.h>

using namespace std; 

vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<pair<int,int>> temp_coordinates;

int n, k;
void bubbleUp(int c, int ref){
    int x = ref;
    while(grid[x][c] == 0 && x != 0) x--;
    if(x == ref) return;
    else swap(grid[ref][c], grid[x][c]);
    return;
}

void applyGravity(int c){
    for(int i = n-1; i >= 0;i--){
        bubbleUp(c, i);
    }
    return;
}

void applyGravityToAll(){
    for(int i = 0; i < 10; i++){
        applyGravity(i);
    }
    return;
}

void floodFill(int r, int c, int last){
    if(r >= n || r < 0 || c < 0 || c >= 10){
        return;
    }
    if(visited[r][c]){
        return;
    }
    if(grid[r][c] == 0){
        return;
    }
    if(grid[r][c] != last){
        return;
    }
    visited[r][c] = true;
    temp_coordinates.push_back(make_pair(r,c));
    floodFill(r,c+1,last);
    floodFill(r+1,c,last);
    floodFill(r,c-1,last);
    floodFill(r-1,c,last);
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    auto clearCells = [&](){
        for(int k = 0; k < temp_coordinates.size();k++){
            grid[temp_coordinates[k].first][temp_coordinates[k].second] = 0;
        }
    };

    freopen("mooyomooyo.in","r",stdin);
    freopen("mooyomooyo.out","w",stdout);
    cin >> n >> k;
    grid = vector<vector<int>>(n);
    visited = vector<vector<bool>>(n);
    for(int i = 0; i < n;i++){
        grid[i].resize(10);
        visited[i].resize(10);
        string s; cin >> s;
        for(int j = 0; j < 10;j++){
            grid[i][j] = int(s[j] - '0');
            visited[i][j] = false;
        }
    }

    for(int i = 0; i < n;i++){
        temp_coordinates.clear();
        for(int j = 0; j < 10;j++){
            if(!visited[i][j] && grid[i][j] != 0){
                int val = grid[i][j];
                floodFill(i,j,val);
                if(temp_coordinates.size() >= k){
                    clearCells();
                }
                temp_coordinates.clear();
            }
        }
    }
    for(int i = 0; i < n;i++){
        for(int j = 0; j < 10;j++){
            visited[i][j] = false;
        }
    }
    applyGravityToAll();
    for(int i = 0; i < n;i++){
        temp_coordinates.clear();
        for(int j = 0; j < 10;j++){
            if(!visited[i][j] && grid[i][j] != 0){
                int val = grid[i][j];
                floodFill(i,j,val);
                if(temp_coordinates.size() >= k){
                    clearCells();
                }
                temp_coordinates.clear();
            }
        }
    }
    applyGravityToAll();
    for(int i = 0; i < n;i++){
        for(int j = 0; j < 10;j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}