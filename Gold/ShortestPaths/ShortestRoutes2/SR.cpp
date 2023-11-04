#include <bits/stdc++.h>
#define ll long long

using namespace std; 
int n, m, q;
vector<vector<int>> floydWarshall;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("SR.in","r",stdin);
    cin >> n >> m >> q;
    floydWarshall = vector<vector<int>>(n,vector<int>(n,1e5));

    for(int i = 0; i < m;i++){
        int a, b, c; cin >> a >> b >> c;
        a--;
        b--;
        if(c < floydWarshall[a][b]){
            floydWarshall[a][b] = c;
            floydWarshall[b][a] = c;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
            floydWarshall[i][j] = min(floydWarshall[i][j],floydWarshall[i][k]+floydWarshall[k][j]);
            floydWarshall[j][i] = min(floydWarshall[j][i],floydWarshall[i][k]+floydWarshall[k][j]);
            }
        }
    }
    while(q--){
        int a, b; cin >> a >> b;
        if(a == b){
            cout << 0 << endl;
        }else if(floydWarshall[a][b] == 1e5){
            cout << -1 << endl;
        }else{
            cout << floydWarshall[a][b] << endl;
        }
    }
    return 0;
}