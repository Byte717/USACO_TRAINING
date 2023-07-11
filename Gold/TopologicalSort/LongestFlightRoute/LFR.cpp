#include <bits/stdc++.h>
#define ll long long
#define INF 1e5

using namespace std; 
int n, m;
vector<vector<int>> adj, radj;
vector<int>  inDegree, dist, previous;

void longestPath(){
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(inDegree[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int front = q.front(); q.pop();

        for(int n : adj[front]){
            inDegree[n]--;
            if(inDegree[n] == 0) q.push(n);
        }
        int MX = -1, MXNode = -1;

        for(int node : radj[front]){
            if(dist[node] + 1 > MX){
                MX = dist[node] + 1;
                MXNode = node;
            }
        }
        previous[front] = MXNode;
        dist[front] = (front == 0) ? 1 : MX;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("LFR.in","r",stdin);
    cin >> n >> m;
    adj = vector<vector<int>>(n); radj = vector<vector<int>>(n);
    inDegree = vector<int>(n,0); dist = vector<int>(n, 0); previous = vector<int>(n);
    for(int i = 0; i < m;i++){
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
        inDegree[b]++;
        radj[b].push_back(a);
    }
    longestPath();

    cout << dist[n-1] << endl;
    int Curr = n-1, nodesCounted = dist[n-1];
    while(nodesCounted > 0){
        cout << previous[Curr]+1 << " ";
        Curr = previous[Curr];
        nodesCounted --;
    }
    return 0;
}