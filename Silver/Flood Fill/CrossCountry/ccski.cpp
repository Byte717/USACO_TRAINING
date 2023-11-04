#include <bits/stdc++.h>

typedef long long ll;
using namespace std; 

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ccski.in","r",stdin);
    int n, m; cin >> n >> m;
    vector<vector<ll>> elevations(n,vector<ll>(m));
    vector<vector<ll>> peaks(n,vector<ll>(m));
    int startI,startJ;
    ll MX = -1, MN = 1e9;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            cin >> elevations[i][j];
            MX = max(MX, elevations[i][j]);
            MN = min(MN, elevations[i][j]);
        }
    }
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            cin >> peaks[i][j];
            if(peaks[i][j]){
                startI = i;
                startJ = j;
            }
        }
    }
    vector<vector<bool>> visited(n,vector<bool>(m));
    int numVisited = 0;

    auto outOfBounds = [&](int x1, int y1){
        return x1 >= n ||  x1 < 0 || y1 >= m || y1 < 0;
    };

    function<void(int,int,int)> floodfill = [&](int i, int j, int d){
        if(i >= n || i < 0 || j >= m || j < 0){
            return;
        }
        if(visited[i][j]) return;
        visited[i][j] = true;
        for(int k = 0; k < 4;k++){
            int newI = i + dirX[k];
            int newJ = j + dirY[k];
            if(!outOfBounds(newI,newJ) && abs(elevations[newI][newJ] - elevations[i][j]) <= d){
                floodfill(newI,newJ, d);
            }
        }
    };

    auto works = [&](int D){
        numVisited = 0;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                visited[i][j] = false;
            }
        }
        floodfill(startI,startJ, D);
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                if(peaks[i][j] == 1 && !visited[i][j]){return false;}
            }
        }
        return true;
    };

    ll low = MN, high = MX, ans;
    while(low <= high){
        ll mid = low + (high - low)/2;
        if(works(mid)){
            high = mid - 1;
            ans = mid;
        }else{
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}