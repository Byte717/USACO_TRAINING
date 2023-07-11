#include <bits/stdc++.h>
#define ll long long

using namespace std; 
const int MAXN = 2e5;

vector<int> adj[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("treeMatch.in","r",stdin);
    int n; cin >> n;
    for(int i = 0; i < n;i++){
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    return 0;
}