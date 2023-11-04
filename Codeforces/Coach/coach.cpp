#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;



int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("coach.in","r",stdin);
    int n, m; cin >> n >> m;
    if(m == 0){
        for(int i = 0; i < n/3;i++){
            for(int j = i+1; j < i + 4;j++){
                cout << j << ' ';
            }
            cout << endl;
        }
        return 0;
    }
    vector<vector<int>> adj(n);
    vector<int> component;
    vector<vector<int>> allGroups;
    vector<bool> vis(n,false);
    for(int i = 0; i < m;i++){
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    function<int(int)> dfs = [&](int node){
        vis[node] = true;
        component.push_back(node);
        int num = 1;
        for(auto& n : adj[node]){
            if(!vis[n]){
                num += dfs(n);
            }
        }
        return num;
    };
    vector<vector<int>> waiting;
    for(int i = 0; i < n;i++){
        if(!vis[i]){
            component.clear();
            int res = dfs(i);
            if(res == 3){
                allGroups.push_back(component);
            }else if(res > 3){
                cout << -1 << endl;
                return 0;
            }else{
                waiting.push_back(component);
            }
        }
    }
    for(int i = 0; i < allGroups.size();i++){
        for(int j = 0; j < allGroups[i].size();j++){
            cout << allGroups[i][j] + 1 << ' ';
        }
        cout << endl;
    }
    vector<vector<int>> ones, twos;
    for(int i = 0; i < waiting.size();i++){
        if(waiting[i].size() == 2){
            twos.push_back(waiting[i]);
        }else{
            ones.push_back(waiting[i]);
        }
    }
    if(twos.size() > ones.size()){
        cout << -1 << endl;
        return 0;
    }
    int lastOne = 0;
    for(int i = 0; i < twos.size();i++){
        cout << twos[i][0]+1 << ' ';
        cout << twos[i][1]+1 << ' ';
        cout << ones[i][0]+1 << endl;
    }
    int printed = 0;
    for(int i = lastOne; i < ones.size();i++){
        if(printed == 3){
            printed = 0;
            cout << endl;
        }
        cout << ones[i][0]+1 << ' ';
    }
    return 0;
}