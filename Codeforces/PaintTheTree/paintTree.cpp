#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+10;
vector<int> g[N];
int dep[N],f[N],mx,n,a,b;
void dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    mx = max(mx,dep[x]);
    f[x]=fa;
    for(auto i:g[x]){
        if(i==fa)continue;
        dfs(i,x);
    }
}
vector<int> move(int x,int y){
    if (dep[x] > dep[y]) swap(x, y);
    vector<int> track,ano;
    int tmp = dep[y] - dep[x], ans = 0;
    track.push_back(y);
    while(tmp--){
        y = f[y];
        track.push_back(y);
    }
    if (y == x) return track;
    ano.push_back(x);
    while (f[x] != f[y]) {
        x = f[x];
        y = f[y];
        ano.push_back(x);
        track.push_back(y);
    }
    track.push_back(f[y]);
    reverse(ano.begin(),ano.end());
    for(auto i:ano)track.push_back(i);
    return track;
}
int main(){
    int t;
    cin>>t;
    dep[0]=-1;
    while(t--){
        mx = -1;
        cin>>n;
        for(int i=1;i<=n;i++)g[i].clear();
        cin>>a>>b;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(a==b){
            dfs(a,0);
            cout<<2*(n-1)-mx<<"\n";
            continue;
        }
        dfs(1,0);
        auto tr = move(a,b);
        int m = tr.size();
        if(tr[0]!=a)reverse(tr.begin(),tr.end());
        int x = tr[(m-1)/2];
        mx = -1;
        dfs(x,0);
        cout<<2*(n-1)-mx+(m-1-(m-1)/2)<<"\n";
    }
}