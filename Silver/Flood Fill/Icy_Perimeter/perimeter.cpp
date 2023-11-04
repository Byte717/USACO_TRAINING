#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1005;


char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int currentP=0,currentA = 0, n;

void floodFill(int r,int c){
    if(r < 0 || r >= n || c < 0 || c >= n){
        currentP++;
        return;
    }
    if(visited[r][c]) return;
    if(grid[r][c] == '.'){
        currentP++;
        return; 
    }
    if(!visited[r][c] && grid[r][c] == '#'){
        currentA++;
        visited[r][c] = true;
    }
    floodFill(r,c+1);
    floodFill(r+1,c);
    floodFill(r,c-1);
    floodFill(r-1,c);
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("perimeter.in","r",stdin);
    freopen("perimeter.out","w",stdout);
    cin >> n; 
    for(int i=0; i < n;i++){
        for(int j = 0; j < n;j++){
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }
    int maxArea = -1, maxPerimeter = -1;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            if(!visited[i][j] && grid[i][j] == '#'){
                floodFill(i,j);
                if(currentA == maxArea){
                    maxPerimeter = min(maxPerimeter,currentP);
                }else if(currentA > maxArea){
                    maxArea = currentA;
                    maxPerimeter = currentP;
                }
                currentA = 0;
                currentP = 0;
            }
        }
    }
    cout << maxArea << " " << maxPerimeter << endl;
    return 0; 
}