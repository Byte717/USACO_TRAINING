#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int deltaX = 0, deltaY = 0, deltaZ = 0; 
    int n; cin >> n;
    for(int i = 0; i < n;i++){
        int x, y, z; cin >> x >> y >> z;
        deltaX += x; deltaY += y; deltaZ += z;
    }
    if(deltaX == 0 && deltaY == 0 && deltaZ == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}