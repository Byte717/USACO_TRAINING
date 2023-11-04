#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

struct patch{
    int x, c;
    bool rightMax;
};

bool cmp(patch &p1, patch &p2){
    return p1.x < p2.x;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n, l, rf, rb; cin >> n >> l >> rf >> rb;
    vector<patch> patches;
    for(int i = 0; i < n;i++){
        int a, b; cin >> a >> b;
        patches.push_back({a,b,false});
    }
    sort(all(patches),cmp);
    int MX = -1;
    for(int i = n-1;i>=0;i--){
        if(patches[i].c  > MX){
            patches[i].rightMax = true;
            MX = patches[i].c;
        }
    }
    int ans = 0;
    int lastStop = 0;
    for(int i = 0; i < n;i++){
        if(patches[i].rightMax){
            int dist = patches[i].x-lastStop;
            int BessieTime = dist*rb;
            int fjTime = dist*rf;
            ans += (BessieTime-fjTime) * patches[i].c;
            lastStop = patches[i].x;
        }
    }
    return 0;
}
