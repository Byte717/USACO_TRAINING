#include <iostream>
#include <cstdio>
#include <vector>

using namespace std; 

const int MAXN = 1000;
bool grid[MAXN][MAXN];

bool comfy(int x, int y){
    int n = 0; 
    if(x - 1 >= 0){
        if(grid[x-1][y]){
            n++;
        }
    }
    if( y - 1 >= 0){
        if(grid[x][y-1]){
            n++;
        }
    }
    if(grid[x+1][y]) n++;
    if(grid[x][y+1]) n++;
    return n == 3;
}

int numComfy(int x, int y){
    int num = 0;
    for(int i = x-2; i <= x+2;i++){
        for(int j = y - 2; j <= x+2;j++){
            if(i < 0 || j < 0) continue;
            if(grid[i][j]){
                if(comfy(i,j)){
                    num++;
                }
            }
        }
    }
    return num;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("comfortable.in","r",stdin);
    int n; cin >> n;
    vector<pair<int,int> > pos(n);
    for(int i = 0; i < n;i++){
        cin >> pos[i].first >> pos[i].second;
    }
    int comfyCount = 0; 
    for(int i = 0; i < n;i++){
        int comfyBefore = numComfy(pos[i].first,pos[i].second);
        grid[pos[i].first][pos[i].second]= true;
        int comfyAfter = numComfy(pos[i].first,pos[i].second);
        if(comfyBefore > comfyAfter){
            comfyCount-=comfyBefore-comfyAfter;
        }else{
            comfyCount+=comfyAfter-comfyBefore;
        }
        cout << comfyCount << endl;
    }
    return 0;
}
