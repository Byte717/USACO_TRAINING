#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("matrix.in","r",stdin);
    int n, m, d; cin >> n >> m >> d;
    int MX = -1;
    vector<vector<int>> mtx(n, vector<int>(m));
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            cin >> mtx[i][j];
            MX = max(MX, mtx[i][j]);
        }
    }
    int ans = INT32_MAX;
    for(int x = 0; x <= MX;x+=d){
        int operations = 0;
        bool check = true;
        for(int i = 0;i < n;i++){
            for(int j = 0; j < m;j++){
                if(mtx[i][j] == x){
                    continue;
                }
                operations += (abs(x-mtx[i][j])/d);
                if(abs(x-mtx[i][j]) % d != 0){
                    check = false;
                    continue;
                }
            }
        }
        if(check) ans = min(ans, operations);
    }
    cout << (ans == INT32_MAX ? -1 : ans) << endl;
    return 0;
}