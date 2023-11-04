#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

vector<pair<ll,ll>> intervals;
vector<bool> vis;

void dfs(int x){
    if(vis[x]) return;
    vis[x] = true;
    ll a = intervals[x].first, b = intervals[x].second;
    for(int i = 0; i < intervals.size();i++){
        if(i == x){
            continue;
        }
        ll c = intervals[i].first, d = intervals[i].second;
        if(c < a && a < d){
            dfs(i);
        }
        if(c < b && b < d){
            dfs(i);
        }
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("pingPong.in","r",stdin);
    int n; cin >> n;
    for(int i = 0; i < n;i++){
        int type; cin >> type;
        if(type == 1){
            int a, b; cin >> a >> b;
            intervals.push_back({--a,--b});
            vis = vector<bool>(intervals.size(),false);
        }else{
            fill(all(vis),false);
            ll x, y; cin >> x >> y;
            x--; y--;
            dfs(x);
            if(vis[y]){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}