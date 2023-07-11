#include <bits/stdc++.h>
#define ll long long
#define INF 1e5

using namespace std; 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("FD.in","r",stdin);
    int n,m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0; i < m;i++){
        int a, b,c; cin >> a >> b >> c;
        adj[a-1].push_back({b-1,c});
    }
    vector<int> dist(n,INF);// dist, max Path length
    

    return 0;
}