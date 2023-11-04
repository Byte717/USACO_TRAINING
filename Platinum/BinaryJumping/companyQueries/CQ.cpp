#include <bits/stdc++.h>

using namespace std; 
int n, q;
int log;
vector<vector<int>> up;
vector<int> parent;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("cq.in","r",stdin);
    cin >> n >> q;
    while((1 << (log+1)) <= n){
        log++;
    }
    parent = vector<int>(n);
    parent[0] = 0;
    for(int i = 1; i < n;i++){
        int a; cin >> a;
        parent[i] = --a;
    }

    up = vector<vector<int>>(n,vector<int>(log));

    // up[v][j] = node v's ancestor 2^j levels up

    for(int v = 0; v < n;v++){
        up[v][0] = parent[v];
        for(int j = 0; j < log;j++){
            up[v][j] = up[ up[v][j-1] ][j-1];
        }
    }
    for(int i = 0; i < q;i++){
        int x, k; cin >> x >> k;
        for(int j = 0; j < log;i++){
            if(k & pow(2,j)){
                x = up[x][j];
            }
        }
    }


    return 0;
}