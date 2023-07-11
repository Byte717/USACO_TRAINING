#include <bits/stdc++.h>
// #define ll long long
// #define INF 1e5

using namespace std; 
const int MAXN = 1e5;

bool visited[MAXN], on_stack[MAXN], partOfCycle[MAXN];
int number_of_cycles = 0, next_node[MAXN];
int n;

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


void dfs2(int n){
    a = next_node[n];
    b = next_node[next_node[n]];
    while(a != b){
        a = next_node[n];
        b = next_node[next_node[n]];
    }
    
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("shuffle.in","r",stdin);freopen("shuffle.out","w",stdout);
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> next_node[i];
        next_node[i]--;
    }
    for(int i = 0; i < n;i++){
        if(!visited[i])dfs(i);
    }
    int ans = 0;
    for(int i = 0; i < n;i++){
        if(partOfCycle[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}