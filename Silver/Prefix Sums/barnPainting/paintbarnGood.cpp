#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

const int WIDTH = 1000;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("paintbarn.in","r",stdin);
    freopen("paintbarn.out","w",stdout);
    int n, k; cin >> n >> k;
    int barn[WIDTH+1][WIDTH+1];

    for(int i = 0; i < n;i++){
        int x1, y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        x1++;y1++;y2++;x2++;
        barn[x1][y1]++;
        barn[x2][y2]++;
        barn[x1][y2]--;
        barn[x2][y1]--;
    }

    int ans = 0;
    for(int i = 1; i <= WIDTH;i++){
        for(int j = 1;j <= WIDTH;j++){
            barn[i][j] = barn[i][j] + barn[i-1][j] + barn[i][j-1] - barn[i-1][j-1];
            if(barn[i][j] == k){ans++;}
        }   
    }
    cout << ans << endl;
    return 0;
}