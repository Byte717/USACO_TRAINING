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

vector<int> next_node; 
vector<ll> moos;
ll total = 0;
vector<bool> vis, onStack;
bool loop = false;
ll MINCOMPONENT = INF; 
void dfs(int node){
    vis[node] = onStack[node] = true;
    MINCOMPONENT = min(MINCOMPONENT,moos[node]);
    int u = next_node[node];
    if(onStack[u]){
        loop = true;
    }else if(!vis[u]){
        dfs(u);
    }
    onStack[node] = false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("visits.in","r",stdin);
    int n; cin >> n;
    next_node = vector<int>(n); moos = vector<ll>(n);
    for(int i = 0; i < n;i++){
        cin >> next_node[i] >> moos[i];
        next_node[i]--;
        total += moos[i];
    }
    vis = vector<bool>(n,false), onStack = vector<bool>(n,false);
    for(int i = 0; i < n;i++){
        if(!vis[i]){
            loop = false;
            fill(all(onStack),false);
            MINCOMPONENT = INF;
            dfs(i);
            if(loop){
                if(MINCOMPONENT == INF){
                    continue;
                }
                total -= MINCOMPONENT;
            }
        }
    }
    cout << total << endl;
    return 0;
}