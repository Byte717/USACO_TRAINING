#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

vector<vector<int>> adj;
map<pair<int,int>, int> weights;
vector<pair<int,int>> bales;
int n, m,k;



void dks(int start, vector<int> & dist){
    vector<bool> vis(n);
    priority_queue<pair<int,int>> q; 
    q.push({0,start});
    dist[start] = 0;
    while(!q.empty()){
        auto &[d,p] = q.top();
        d = -d;
        if(vis[p]) continue;
        for(auto node : adj[p]){
            int cw = weights[{p,node}];
            if(d + cw < dist[node]){
                dist[node] = d + cw;
                q.push({-dist[node], node});
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    cin >> n >> m >> k;
    bales = vector<pair<int,int>>(k);
    adj = vector<vector<int>>(n+2);
    for(int i = 0; i < m;i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        weights[{a,b}] = c;
        weights[{b,a}] = c;
    }

    for(int i = 0; i < k;i++){
        int a, b; cin >> a >> b;
        bales[i] = {a,b};
    }
    vector<int> dist1(n,INT32_MAX);
    dks(n, dist1);
    vector<int> newND;
    for(int i = 0; i < k;i++){
        newND.push_back(bales[i].first);
        weights[{n+1, bales[i].first}] = dist1[bales[i].first] - bales[i].second; // cost to come here 
    }
    adj[n+1] = newND;
    vector<int> dist2(n,INT32_MAX);
    dks(n+1, dist2);
    for(int i = 0; i < k;i++){
        if(dist2[i] > dist1[i]){
            cout << 0 << endl;
        }else{
            cout << 1 << endl;
        }
    }
    return 0;
}