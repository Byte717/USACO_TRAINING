#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> graph;
vector<int> connected;



void dfs(int node){

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("wormsort.in","r",stdin);
    int n, m; cin >> n >> m; 
    vector<int> cows(n);
    
    graph.resize(n);
    for(auto& i : cows) cin >> i;
    int a, b, w;
    int maxWidth = -1;
    for(int i = 0; i < n;i++){
        cin >> a >> b >> w;
        graph[--a].push_back(make_pair(--b,w));
        graph[b].push_back(make_pair(a,w));
        maxWidth = max(maxWidth, w);
    }

    int low = 0, hi = maxWidth, mid;

    while(low <= hi){
        mid = low + (hi - low)/2;
        connected = vector<int>(n, -1);

    }



    return 0;
}