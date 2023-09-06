#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std; 

/*
Solution: sort all points of a lifeGuard, starts and ends and iterate through. Then we keep a set for
active guards. Greedily, you want to fire the guard that spends the most time alone. 
So the prev time variable keeps a track of the last point's time. so if there are multiple cows till point, the total will be current point - prev, since
if they all cover a collective amount of time. on the other case, there will be 1 cow in the set, so set its alone time accordingly


*/
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
