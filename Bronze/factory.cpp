#include <bits/stdc++.h>

using namespace std; 
vector<vector<int>> graph;
int n;
bool visited[100];

void dfs(int n){
    visited[n] = true;
    for(int node : graph[n]){
        if(!visited[node]){
            dfs(node);
        }
    }
}



int main(){
    freopen("factory.in","r",stdin);
    cin>>n;
    graph = vector<vector<int>>(n+1);
    vector<int> done; 
    for(int i = 0; i < n-1;i++){
        int s1,s2;
        cin >> s1 >> s2;
        graph[s2].push_back(s1);
    }
    for(int i = 1; i <= n;i++){
        fill(begin(visited),end(visited), false);
        dfs(i);
        bool ok = true;
        for(int i = 1; i <= n; i++){
            if(visited[i] == false){
                ok = false;
                break;
            }
        }
        if(ok){
            done.push_back(i);
        }
    }
    if(done.size() == 0){
        cout << -1 << endl;
    }else{
        cout << *min_element(done.begin(),done.end());   
    }
    return 0; 
}