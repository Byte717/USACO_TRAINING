#include <bits/stdc++.h>
// #define ll long long
// #define INF 1e5

using namespace std; 
const int MAXN = 1e2;

bool visited[MAXN], on_stack[MAXN], partOfCycle[MAXN];
int number_of_cycles = 0, next_node[MAXN];
int n;
int globalAns = 0;
void dfs(int n) {
	visited[n] = on_stack[n] = true;
	int u = next_node[n];
	if (on_stack[u]){
        number_of_cycles++;
        partOfCycle[u] = true;
        partOfCycle[n] = true;
    }
	else if (!visited[u]) dfs(u);
	on_stack[n] = false;
}


void dfs2(int node){
    int a = next_node[node];
    int b = next_node[next_node[node]];
    while(a != b){
        a = next_node[a];
        b = next_node[next_node[b]];
    }
    a = node;
    while(a != b){
        a = next_node[a];
        b = next_node[b];
    }
    int firstNode = a;
    b = next_node[a];
    int len = 1;
    while(a != b){
        visited[b] = true;
        b = next_node[b];
        len++;
    }
    globalAns += len;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("shuffle.in","r",stdin);
    // freopen("shuffle.out","w",stdout);
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> next_node[i];
        next_node[i]--;
    }
    for(int i = 0; i < n;i++){
        if(!visited[i])dfs2(i);
    }
    int ans = 0;
    for(int i = 0; i < n;i++){
        if(partOfCycle[i]) ans++;
    }
    cout << ans << endl;
    cout << globalAns << endl;
    return 0;
}