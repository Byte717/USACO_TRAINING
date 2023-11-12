#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

struct Data{
    int dist;
    int idx;
};
auto cmp =  [](const Data& a, const Data&b){if(a.dist == b.dist) return a.idx < b.idx; return a.dist < b.dist;};

vector<Data> d;
int n, k;
bool impossible = false;
vector<pair<int,int>> ans;

void dfs(int node,int parent,int idx){
    int connected = 0;
    vector<int> dfsList;
    int initialDist = d[idx].dist;
    if(node != d[idx].idx){dfsList.push_back(d[idx].idx); ans.push_back({node, d[idx].idx}); connected++;}

    while(idx + 1 < d.size() && d[++idx].dist == initialDist){
        if(node == d[idx].idx) continue;
        dfsList.push_back(d[idx].idx);
        ans.push_back({node, d[idx].idx});
        connected++;
    }

    if(connected > k){
        impossible = true;
        return;
    }

    for(auto& v : dfsList){
        if(v != node && idx < n){
            dfs(v,node, idx);
        }
    }
}

void bfs(int start, int idx){
    vector<bool> vis(n,false);
    queue<pair<int,int>> q;
    q.push({start,0});
    while(!q.empty()){
        int top = q.front().first;
        int dist = q.front().second;
        q.pop();

        if(vis[top]) continue;

        if(idx >= n){
            break;
        }
        int connected = 0;
        vector<int> adj;
        while(idx < n && d[idx].dist == dist+1 && connected < k-1){
            ans.push_back({top,d[idx].idx});
            q.push({d[idx].idx, d[idx].dist});
            idx++;
            connected++;
        }
        if(connected > k){
            impossible = true;
            break;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("restore.in","r",stdin);
    cin >> n >> k;
    d = vector<Data>(n);
    for(int i = 0; i < n;i++){
        cin >> d[i].dist;
        d[i].idx = i;
    }
    
    sort(all(d),cmp);
    bool seenZero = false;

    for(int i = 0; i < n;i++){
        if(seenZero == true && d[i].dist == 0){
            cout << -1 << endl;
            return 0;
        }else if(d[i].dist == 0){
            seenZero = true;
        }
    }
    if(!seenZero){
        cout << -1 << endl;
        return 0;
    }
    bfs(d[0].idx,1);

    if(impossible){
        cout << -1 << endl;
        return 0;
    }

    cout << ans.size() << endl;
    for(auto &[x,y] : ans){
        cout << x+1 << " " << y+1 << endl;
    }
    return 0;
}