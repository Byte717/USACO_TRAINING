#include <bits/stdc++.h>

using namespace std;
const int MAXN = 3000;

vector<bool> visited(MAXN, false);
vector<vector<int>> farm;
set<int> removed;
vector<int> removeOrder;

void dfs(int node){
    if(visited[node] || removed.count())
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("closing.in","r",stdin);
    int n, m; cin >> n >> m;
    farm = vector<vector<int>>(n);
    removeOrder = vector<int>(m);
    for(int i = 0; i < m;i++){
        int a, b; cin >> a >> b; 
        --a; --b;
        farm[a].push_back(b);
    }
    for(int i = 0; i < n;i++){
        cin >> removeOrder[i];
        removeOrder[i]--;
    }
    for()




    return 0;
}