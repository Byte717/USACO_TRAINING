#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

struct Node{
    int left, right;
};

#define LEFT -1
#define RIGHT 1


vector<Node> graph;
vector<int> last;
int n; 
string original;
map<pair<int,int> , int>> m;
vector<int> dist;

void dfs(int node){
    if(graph[node].left != -1){
        dist[graph[node].left] = dist[node] + *m.find({node, graph[node].left});
        dfs(graph[node].left);   
    }

    if(graph[node].right != -1){
        dist[graph[node].right] = dist[node] + *m.find({node, graph[node].right});
        dfs(graph[node].right);
    }
}

void solve(){
    cin >> n; cin >> original;
    graph = vector<Node>(n);
    dist = vector<int>(n,INT32_MAX);
    vector<int> vertexes;
    for(int i = 0; i < n;i++){
        int l, r; cin >> l >> r;
        l--; r--;
        if(l < 0 && r < 0){
            vertexes.push_back(i);
        }
        graph[i].left = l;
        graph[i].right = r;
        m.insert({i,l}, (original[i] == 'L') ? 0 : 1);
        m.insert({i,r}, (original[i] == 'R') ? 0 : 1);
    }

    dist[0] = 0;
    dfs(0);
    int ans = 1000000;
    for(auto i : vertexes){
        ans = min(ans, dist[i]);
    }
    cout << ans << endl;
}



int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}