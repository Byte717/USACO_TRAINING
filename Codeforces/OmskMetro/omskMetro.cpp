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


struct info{
    int minSuf = 0;
    int maxSuf = 0;
    int maxAns = 0;
    int minAns = 0;
};



void solve(){
    int n; cin >> n;

    info start;
    start.maxSuf = start.maxAns = 1;
    vector<info> st;
    for(int i = 0; i < n;i++){
        char type; cin >> type;
        if(type == '+'){
            int v, x; cin >> v >> x;
            info pref = st[v];
            info curr;
            curr.minSuf = min(0, pref.minSuf + x);
            curr.maxSuf = max(0,pref.maxSuf+x);
            curr.minAns = min(pref.minAns,curr.minSuf);
            curr.maxAns = max(pref.maxAns, curr.maxSuf);
        }else{
            int v, x; cin >> v >> x;
            if(st[v].minAns <= x && x <= st[v].maxAns){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}