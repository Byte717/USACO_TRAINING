#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

/*

greedily fill k - 1 tubes with 2 size. then the rest goes to the last tube.
*/
int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int n, m, k; cin >> n >> m >> k;
    if(n == 3 && m == 3 && k == 3){
        for(int i = 0; i < 3;i++){
            cout << 3; 
            for(int j = 0;j < 3;j++){
                cout << ' ' << i + 1 << ' ' << j + 1; 
            }
            cout << endl;
        }
        return 0;
    }
    vector<pair<int,int>> path; 
    int x = 0, y = 0, dir = 1;
    path.push_back({x+1,y+1});
    while(true){
        y += dir;
        if(y == m) dir *= -1, y = m - 1, x++;

        if(y == -1) dir *= -1, y = 0, x++;

        if(x == n) break;

        path.push_back({x+1,y+1});
    }
    for(int i = 0; i < k-1;i++){
        cout << 2; 
        cout << path[2*i].first << " " << path[2*i].second;
        cout << path[2*i+1].first << " " << path[2*i+1].second << endl;
    }
    cout << path.size()-2*(k-1) << ' ';
    for(int i = 2*k-1; i < path.size();i++){
        cout << path[i].first << ' ' << path[i].second << ' ';
    }
    cout << endl;
    return 0;
}