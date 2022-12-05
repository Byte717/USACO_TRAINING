#include <bits/stdc++.h>

using namespace std; 

int ans = 0; 
char grid[50][50];
int k;

void recursive(int x, int y, int n, int directionsChanged, char direction){
    if(x >= n || x < 0 || y >= n || y < 0){
        return;
    }
    if(grid[x][y] == 'H'){
        return;
    }
    if(x == n-1 && y == n-1){
        ans++; 
        return;
    }
    if(directionsChanged > k){
        return;
    }
    if(direction == 'D'){
        recursive(x,y+1,n,directionsChanged,direction);
        recursive(x+1,y,n,directionsChanged+1,'R');
    }else{
        recursive(x+1,y,n,directionsChanged,direction);
        recursive(x,y+1,n,directionsChanged+1,'D');
    }

    
}



void solve(){
    int n;cin>>n>>k;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            cin >> grid[i][j];
        }
    }
    recursive(0,0,n,0,'D');
    cout << ans << endl;
    ans = 0;
}


int main(){
    freopen("walkHome.txt", "r", stdin);
    int t;cin>>t;
    for(int i = 0; i < t;i++){
        solve();
    }

    return 0;
}