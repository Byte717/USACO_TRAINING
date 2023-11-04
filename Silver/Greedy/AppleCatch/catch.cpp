#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

struct item{
    int type;
    ll time, pos, num;

    bool operator<(const item &y){
        if(pos - time == y.pos - y.time){ return type > y.type;}
        return pos - time < y.pos - y.time;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;
    vector<item> p(n);
    for(int i = 0; i < n;i++){
        cin >> p[i].type >> p[i].time >> p[i].pos >> p[i].num;
    }
    sort(all(p));
    map<int,int> pts; // {location, num available}
    int ans = 0; 
    for(int i = 0; i < n;i++){
        if(p[i].type == 2){
            pts[p[i].pos + p[i].time] += p[i].num;
        }else{ // cows deployed
            int n = p[i].num;
            while(n){
                auto it = pts.lower_bound(p[i].x + p[i].t);
                if(it == pts.end()) break;
                int u = min(n, it->second);
                if(u == it->second){
                    pts.erase(it);
                }else{
                    it->second -= u;
                }
                n -= u;
                ans += u;
            }
        }
    }
    cout << ans << endl;
    return 0;
}