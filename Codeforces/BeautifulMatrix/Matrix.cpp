#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int midX = 2, midY = 2;
    int X,Y;
    for(int i = 0; i < 5;i++){
        for(int j = 0;j < 5;j++){
            int x; cin >> x;
            if(x == 1){
                X = i;
                Y = j;
                break;
            }
        }
    }
    if(X == midX && Y == midY){
        cout << 0 << endl;
    }else{
        cout << abs(X-midX) + abs(Y-midY) << endl;
    }
    return 0;
}