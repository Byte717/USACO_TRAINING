#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std; 

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m;i++){
        int a, b; cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    vector<int> dist(n,INF);
    dist[0] = 0;
    queue<int> q;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto &i : graph[node]){
            if(dist[i] == INF){
                dist[i] = dist[node] + 1;
                q.push(i);
            }
        }
    }
    vector<int> even, odd;
    for(int i = 0; i < n;i++){
        if(dist[i] % 2 == 0){
            even.push_back(i);
        }else{
            odd.push_back(i);
        }
    }

    if(even.size() > odd.size()){
        cout << even.size() << endl;
        for(int &i : even){cout << i + 1 << " ";}
        cout << endl;
    }else{
        cout << odd.size() << endl;
        for(int &i : odd){cout << i + 1 << " ";}
        cout << endl;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int t; cin >> t;
    while(t--){solve();}
    return 0;
}
