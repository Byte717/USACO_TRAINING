#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}
/*
use a stargraph, as there has to be one center node to reach everything else;

What I learned Road Construction:
    - Star graphs, graphs that have a center

*/


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("road.in","r",stdin);
    int n, m; cin >> n >> m;
    set<pair<int,int>> forbidden;
    for(int i = 0; i < m;i++){
        int a, b; cin >> a >> b;
        a--; b--;
        forbidden.insert({a,b});
    }
    int nodesVis = 0;
    for(int center = 0; center < n;center++){
        nodesVis = 0;
        vector<pair<int,int>> edges;
        for(int i = 0; i < n;i++){
            if(i != center && (forbidden.count({center,i}) == 0 && forbidden.count({i,center}) == 0)){
                edges.push_back({center,i});
                nodesVis++;
            }
        }
        if(nodesVis == n-1){
            cout << edges.size() << endl;
            for(auto &[x,y] : edges){
                cout << x+1 << ' ' << y+1 << endl;
            }
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}