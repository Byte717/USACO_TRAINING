#include <bits/stdc++.h>
#define INF 1e18
#define mod 1e9+7

typedef long long ll;

using namespace std; 

string toBinary(int n) {
    if (n==0) return "0";
    else if (n==1) return "1";
    else if (n%2 == 0) return toBinary(n/2) + "0";
    else return toBinary(n/2) + "1";
}


struct edge{
    int to;
    char type;
};

vector<vector<edge>> adj;
vector<bool> visited;
vector<int> color;
bool impossible = false;

void dfs(int node, int c = 0){
    if(visited[node]){
        if(color[node] != c) impossible = true;
        return;
    }
    visited[node] = true;
    color[node] = c;
    for(auto i : adj[node]){
        if(i.type == 'S'){
            dfs(i.to, c);
        }else{
            dfs(i.to,!c);
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("revegetate.in","r",stdin);
    freopen("revegetate.out","w",stdout);
    int n, m; cin >> n >> m;
    adj.resize(n);
    visited = vector<bool>(n,false);
    color = vector<int>(n,-1);
    for(int i = 0; i < m;i++){
        char type; cin >> type;
        int a, b; cin >> a >> b;
        adj[--a].push_back({--b,type});
        adj[b].push_back({a,type});
    }
    int numComponents = 0;
    for(int i = 0; i < n;i++){
        if(color[i] == -1){
            dfs(i);
            numComponents++;
        }
    }
    if(impossible){
        cout << 0 << endl;
        return 0;
    }
    // int ans = 2*numComponents;
    cout << 1;
    for(int i = 0; i < numComponents;i++){
        cout << 0;
    }
    cout << endl;
    // cout << toBinary(ans) << endl;
    return 0;
}