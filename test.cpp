#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> adj;


vector<bool> visited;

void dfs(int node){
	if(visited[node]){
		return;
	}
	visited[node] = true;
	for(int &i : adj[node]){
		dfs(i);
	}
}

void bfs(int start){
	queue<int> q;
	q.push(start);
	while(!q.empty()){

		int top = q.front(); q.pop();

		if(!visited[top]){

			visited[top] = true;

			for(int &i : adj[top]){
				q.push(i);
			}
			
		}
	}
}


int main() {
	int n; cin >> n;
	adj.resize(n);
	for(int i = 0; i < n;i++){
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	 
	return 0;
}

