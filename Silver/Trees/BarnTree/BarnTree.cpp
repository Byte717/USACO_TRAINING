#include <bits/stdc++.h>
#define ll long long
#define INF 1e5

const int MAXN = 2e5;

using namespace std;

struct order{
    int from, to;
    ll amount;
};

int n; 
vector<int> adj[MAXN];
int haybales[MAXN];
int subtreeSum[MAXN];
vector<order> sequnce;
vector<bool> vis(MAXN,false);

int sum(int node,int parent){
    if(vis[node]) return 0;
    vis[node]  = true;
    int curr = haybales[node];
    for(int n : adj[node]){
        if(n != parent){
            curr += sum(n,node);
        }
    }
    subtreeSum[node]  = curr;
    return curr;
}

void dfs(int node,int parent){
    for(int n : adj[node]){
        if(n != parent && subtreeSum[n] > 0){
            dfs(n,node);
        }
    }

    for(int n : adj[node]){
        if(n!= parent && subtreeSum[n] <= 0){
            if(subtreeSum[n] < 0){
                sequnce.push_back({node,n ,-subtreeSum[n]});
            }
            dfs(n,node);
        }
    }
    if(node!=1 && subtreeSum[node] > 0){
        sequnce.push_back({node,parent, subtreeSum[node]});
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("bt.in","r",stdin);
    cin >> n;
    int total = 0;
    for(int i = 0; i < n;i++){
        cin >> haybales[i];
        total+= haybales[i];
    }
    int each = total/n;
    for(int i = 0; i < n;i++){
        haybales[i] -= each;
    }

    for(int i = 0; i < n;i++){
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    sum(1,1);
    // dfs(1,1);

    cout << sequnce.size() << endl;
    for(order i : sequnce){
        cout << i.from << " " << i.to << " " << i.amount << endl;
    }

    return 0;
}