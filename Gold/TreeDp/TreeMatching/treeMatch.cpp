#include <bits/stdc++.h>
#define ll long long

using namespace std; 
const int MAXN = 2e5;

vector<int> adj[MAXN];

bool done [200005];
int ans = 0;
void greedyDfs(int node,int parent){
    for(int n : adj[node]){
        if(n!=parent){
            greedyDfs(n,node);
            if(!done[n] && !done[node]){
                done[n] = true; done[node] = true; 
                ans++;
            }
        }
    }
}




int dp[200005][2];
// dp[i][0] = maximum matching where we don't take an edge that leads to a child of i,
// dp[i][1] = maximum matching where we take 1 edge leading to a child of i


void dfs(int node,int parent){
    for(int n : adj[node]){
        if(n != parent){
            dfs(n,node);
            dp[node][0] += max(dp[n][0], dp[n][1]); // for each child, take how much we can for ech subtree of that child, either connect,or not
        }
    }
    for(int n : adj[node]){
        if(n != parent){
            dp[node][1] = max(dp[node][1], dp[n][0]+1 + dp[node][0]-max(dp[n][0],dp[n][1])); // 
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("treeMatch.in","r",stdin);
    int n; cin >> n;
    for(int i = 0; i < n;i++){
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    // dfs(0,-1);
    // cout << max(dp[0][0], dp[0][1]) << endl;
    // greedyDfs(1,0);
    // cout << ans << endl;
    return 0;
}