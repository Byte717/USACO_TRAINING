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

struct shift{
    int time;
    int id;
    bool is_start;
};

bool cmp(shift &s1, shift &s2){
    return s1.time < s2.time;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;
    vector<shift> v;
    for(int i = 0; i < n;i++){
        int l, r; cin >> l >> r;
        v.push_back({l,i,true});
        v.push_back({r,i,false});
    }
    sort(all(v),cmp);
    vector<int> aloneTime(n);
    set<int> active;
    int PrevTime = 0, total = 0;
    for(auto &i : v){
        int currTime = i.time;
        if(active.size() > 0){total += currTime - PrevTime;}

        if(active.size() == 1){
            aloneTime[*active.begin()] += currTime - PrevTime;
        }
        if(i.is_start){
            active.insert(i.id);
        }else{
            active.erase(i.id);
        }
        PrevTime = currTime;
    }
    int MinAlone = INT32_MAX;
    for(int i = 0; i < n;i++){
        MinAlone = min(MinAlone, aloneTime[i]);
    }
    cout << total - MinAlone << endl;
    return 0;
}
