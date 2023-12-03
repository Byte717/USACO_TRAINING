#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#pragma GCC optimize("O3","unroll-loops")


typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

// input
int n, m, k;
vector<int> a;
vector<pair<int,int>> intervals;

//graph
vector<vector<int>> adj;
vector<bool> vis;
vector<int> cycle;



void input(){
    cin >> n >> m >> k;
    a = vector<int>(n+1);
    for(int i = 1; i <= n;i++){
        a[i] = i;
    }
    intervals = vector<pair<int,int>>(m);
    for(int i = 0; i < m;i++){
        int l, r; cin >> l >> r;
        intervals[i] = {l,r};
    }
}

void swapArr(int l, int r){
    while(l < r){
        swap(a[l],a[r]);
        l++;
        r--;
    }
}

void simulateM(){
    for(int i = 0; i < m;i++){
        swapArr(intervals[i].first, intervals[i].second);
    }
}


void buildGraph(){
    adj = vector<vector<int>>(n+1);
    for(int i = 1; i <= n;i++){
        adj[a[i]].push_back(i);
    }
}


void dfs(int node){
    if(vis[node]) return;
    vis[node] = true;
    cycle.push_back(node);
    for(auto &i : adj[node]){
        dfs(i);
    }
}



void calcForEachComponent(){
    vis = vector<bool>(n+1,false);
    for(int i = 1; i <= n;i++){
        if(vis[i]){
           continue; 
        }
        cycle.clear();
        dfs(i);
        int mod = k % cycle.size();
        for(int j = 0; j < cycle.size();j++){
            a[cycle[j]] = cycle[(j+mod) % cycle.size()]; // the position that cycle[j](or the number in j after m rotations) has to shift forward mod times
        }
    }
}


void printAns(){
    for(int i = 1; i <= n;i++){
        cout << a[i] << endl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("swaps.in","r",stdin);

    input();

    simulateM();

    buildGraph();

    calcForEachComponent();

    printAns();
    
    return 0;
}