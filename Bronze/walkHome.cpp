#include <bits/stdc++.h>

using namespace std; 

char grid[50][50];
int k, n;

int recursive(int x, int y, int directionsChanged, char direction){
    if(x >= n || y >= n)return 0;
    if(grid[x][y] == 'H')return 0;
    if(directionsChanged > k)return 0;
    if(x == n-1 && y == n-1)return 1;
    if(direction == '\0'){
        return recursive(x+1,y,0,'D') + recursive(x,y+1,0,'R');
    }else if(direction == 'D'){
        return recursive(x+1,y,directionsChanged,'D') + recursive(x,y+1,directionsChanged+1,'R');
    }else{
        return recursive(x+1,y,directionsChanged+1,'D') + recursive(x,y+1,directionsChanged,'R');
    }

}

int main(){
    int t;cin>>t;
    for(int i = 0; i < t;i++){
        cin>>n>>k;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                cin >> grid[i][j];
            }
        }
        cout << recursive(0,0,0, '\0') << endl;
    }
    return 0;
}