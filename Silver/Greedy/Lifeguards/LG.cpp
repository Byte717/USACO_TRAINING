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


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("LG.in","r",stdin);
    int n;cin >> n;
    vector<pair<int,int>> lifeGuards;
    for(int i = 0; i < n;i++){
        int a, b; cin >> a >> b;
        lifeGuards.push_back({a,b});
    }
    sort(all(lifeGuards));
    vector<int> timeCovered(n,0);
    int MX = -1;
    for(int i = 0; i < n;i++){
        if(i==0){
            timeCovered[i] = lifeGuards[i].second-lifeGuards[i].first;
            MX = max(MX,lifeGuards[i].second);
            continue;
        }

        if(lifeGuards[i].first < MX){
            if(lifeGuards[i].second <= MX){
                timeCovered[i] = 0;
            }else{
                timeCovered[i] = lifeGuards[i].second - MX;
                MX = lifeGuards[i].second;
            }
        }else{
            MX = lifeGuards[i].second;
            timeCovered[i] = lifeGuards[i].second -lifeGuards[i].first;
        }
    }
    int Total = 0, MIN = INT32_MAX;
    for(int i = 0; i < n;i++){
        Total += timeCovered[i];
        MIN = min(MIN, timeCovered[i]);
    }
    cout << Total-MIN << endl;
    return 0;
}
