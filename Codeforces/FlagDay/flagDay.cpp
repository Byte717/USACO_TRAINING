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
struct Dance{
    int a, b, c;
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("flagDay.in","r",stdin);
    int n, m; cin >> n >> m;
    vector<int> ans(n+1);
    vector<Dance> dances(m);
    for(int i = 0; i < m;i++){
        int a, b, c;cin >> a >> b >> c;
        dances[i]  = Dance{a,b,c};
    }
    vector<int> lastSeen(n+1,-1);
    lastSeen[dances[0].a] = 0, lastSeen[dances[0].b] = 0; lastSeen[dances[0].c] = 0;
    ans[dances[0].a] = 1, ans[dances[0].b] = 2, ans[dances[0].c] = 3;

    for(int i = 1; i < m;i++){
        auto &[a,b,c] = dances[i];
        if(lastSeen[a] != -1){
            if(ans[a] == 1){
                ans[b] = 2;
                ans[c] = 3;
            }else if(ans[a] == 2){
                ans[b] = 1;
                ans[c] = 3;
            }else{
                ans[b] = 2;
                ans[c] = 1;
            }
            lastSeen[b] = i;
            lastSeen[c] = i;
        }else if(lastSeen[b] != -1){
            if(ans[b] == 1){
                ans[a] = 2;
                ans[c] = 3;
            }else if(ans[b] == 2){
                ans[a] = 1; 
                ans[c] = 3;
            }else{
                ans[a] = 1;
                ans[c] = 2;
            }
            lastSeen[a] = i;
            lastSeen[c] = i;
        }else if(lastSeen[c] != -1){
            if(ans[c] == 1){
                ans[a] = 2;
                ans[b] = 3;
            }else if(ans[c] == 2){
                ans[a] = 1;
                ans[b] = 3;
            }else{
                ans[a] = 1;
                ans[b] = 2;
            }
            lastSeen[b] = i;
            lastSeen[a] = i;
        }else{
            lastSeen[a] = i;
            lastSeen[b] = i;
            lastSeen[c] = i;
            ans[a] = 1;
            ans[b] = 2;
            ans[c] = 3;
        }
    }
    for(int i = 1; i <= n;i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}