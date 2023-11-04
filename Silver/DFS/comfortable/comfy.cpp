#include <bits/stdc++.h>

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};


#define Unordered_map  unordered_map<pair<int,int>, set<pair<int,int>>, pair_hash>

int main(){
    freopen("comfy.in","r",stdin);
    Unordered_map graph;
    set<pair<int,int>> uncomfy_cows, visited;
    int n; cin >> n;
    int x, y;
    auto addCow = [&](pair<int,int> cow){
        graph[{x,y}] = set<pair<int,int>>{};
        if(graph.count({x-1,y})){
            graph[{x,y}].insert({x-1,y});
            graph[{x-1,y}].insert({x,y});
        }
        if(graph.count({x,y-1})){
            graph[{x,y}].insert({x,y-1});
            graph[{x,y-1}].insert({x,y});
        }
        if(graph.count({x+1,y})){
            graph[{x,y}].insert({x+1,y});
            graph[{x+1,y}].insert({x,y});
        }
        if(graph.count({x,y+1})){
            graph[{x,y}].insert({x,y+1});
            graph[{x,y+1}].insert({x,y});
        }
    };

     auto markNeighborsAsUnVisited = [&](pair<int,int> cow){
        for(auto i : graph[cow]){
            visited.erase(visited.find(i));
        }
     }; 

     auto markVisited = [&](pair<int,int> cow){
        visited.insert(cow);
     };
    auto markComfortable = [&](pair<int,int> cow){
        uncomfy_cows.erase(uncomfy_cows.find(cow));
    };

    auto markUnComfortable = [&](pair<int,int> cow){
        uncomfy_cows.insert(cow);
    };

    auto isVisited = [&](pair<int,int> cow){
        return visited.count(cow) > 0 ;
    };
    auto nodeExists = [&](pair<int,int> cow, pair<int,int> find){
        return graph[cow].count(find) > 0;
    };
    function<bool(pair<int,int>)> ExistsInGraph(pair<int,int> cow){
        return graph.count(cow) > 0;
    };

    function<int(pair<int,int>)> dfs = [&](pair<int,int> cow){
        if(isVisited(cow)){
            return 0;
        }
        if(!ExistsInGraph(cow)){
            return 0;
        }
        markVisited(cow);
        if(graph[cow].size() != 3){
            markUnComfortable(cow);
            return dfs({cow.first-1,cow.second}) + dfs({cow.first+1,cow.second}) + dfs({cow.first,cow.second-1}) + dfs({cow.first,cow.second+1});
        }else{
            pair<int,int> left= {cow.first-1,cow.second};
            pair<int,int> right = {cow.first+1,cow.second};
            pair<int,int> up = {cow.first,cow.second+1};
            pair<int,int> down = {cow.first,cow.second-1};
            if(!nodeExists(cow,left)){
                addCow(left);
                markNeighborsAsUnVisited(left);
                markVisited(cow);
                return 1 + dfs(left);
            }
            else if(!nodeExists(cow,right)){
                addCow(right);
                markNeighborsAsUnVisited(right);
                markVisited(cow);
                return 1 + dfs(right);
            }
            else if(!nodeExists(cow,up)){
                addCow(up);
                markNeighborsAsUnVisited(up);
                markVisited(cow);
                return 1 + dfs(up);
            }
            else if(!nodeExists(cow,down)){
                addCow(down);
                markNeighborsAsUnVisited(down);
                markVisited(cow);
                return 1 + dfs(down);
            }else{
                return 0;
            }
        }
    };
    for(int i = 0; i < n;i++){
        cin >> x >> y;
        addCow({x,y});
        cout << dfs({x,y}) << endl;
    }
    return 0;
}