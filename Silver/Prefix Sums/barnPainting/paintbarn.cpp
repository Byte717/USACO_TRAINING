#include <iostream> 
#include <vector>


using namespace std;
int n, k;
vector<vector<int>> grid(1001, vector<int>(1001,0));

void paint(int x1, int y1, int x2, int y2){
    for(int i = x1; i < x2;i++){
        for(int j = y1; j < y2;j++){
            grid[i][j]++;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("paintbarn.in","r",stdin);
    freopen("paintbarn.out","w",stdout);
    cin >> n >> k;
    int x1, y1, x2, y2;
    for(int i = 0; i < n;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        paint(x1, y1, x2,y2);
    }
    int ans = 0;
    for(int i = 0; i < 1001;i++){
        for(int j = 0; j < 1001;j++){
            if(grid[i][j] == k){
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}