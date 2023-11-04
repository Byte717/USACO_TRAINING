#include <iostream> 
#include <cstdio> 
#include <vector> 
#include <set>
#include <algorithm>

using namespace std;
int n, m;
vector<vector<int> > graph; 
set<int> visited; vector<int> queue;
vector<int> grass;

// #pragma clang diagnostic push
// #pragma clang diagnostic ignored "-Wc++11-extensions"
int minType(int node){
    int arr[5] = {0,0,0,0,0};
    for(int j : graph[node]){
        arr[grass[j]] += 1;
    }
    for(int j = 1; j <= 4;j++){
        if(arr[j] == 0){
            return j;
        }
    }
    return -1;

}
// #pragma clang diagnostic pop

// #pragma clang diagnostic push
// #pragma clang diagnostic ignored "-Wc++11-extensions"
int main(){
    freopen("revegitate.in","r",stdin);
    cin >> n >> m;
    graph = vector<vector<int> >(n+1);
    grass = vector<int>(n+1);
    fill(grass.begin(),grass.end(),0);
    for(int i = 0; i < m;i++){
        int x, y; 
        cin >> x >> y; 
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    queue.push_back(1);
    while(queue.size() > 0){
        sort(queue.begin(),queue.end());
        visited.insert(queue[0]);
        for(int i : graph[queue[0]]){
            if(!(visited.count(i))){
                queue.push_back(i);
                visited.insert(i);
            }
        }
        grass[queue[0]] = minType(queue[0]);
        queue.erase(queue.begin());
    }
    for(int i = 1; i < (int)grass.size();i++){
        cout << grass[i] << " ";
    }
    cout << endl;


    return 0;
}
// #pragma clang diagnostic pop
