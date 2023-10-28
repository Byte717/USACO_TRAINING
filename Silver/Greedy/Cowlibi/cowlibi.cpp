#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

struct graze{
    ll x, y; 
    ll time;
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n, g; cin >> n >> g;
    vector<graze> crimes;
    for(int i = 0; i < g;i++){
        ll x, y, time; cin >> x >> y >> time;
        crimes.push_back({x,y,time});
    }
    sort(all(crimes),[&](const graze&g1, const graze&g2){
        return g1.time < g2.time;
    });
    vector<ll> times;
    for(int i = 0; i < n;i++){
        times.push_back(crimes[i].time);
    }

    int guilty = 0;
    for(int i = 0; i < n;i++){
        ll x, y, t; cin >> x >> y >> t;
        auto it = lower_bound(all(times),t);
        int idx = it - times.begin();
        for(int j = idx -1 ; j <= idx+1;j++){
            if(j >= 0 && j < g){
                ll distSquared = ((x-crimes[j].x)*(x-crimes[j].x)) + ((y-crimes[j].y)*(y-crimes[j].y));
                ll timeDiff = (crimes[j].time - t)*(crimes[j].time - t);
                if(timeDiff >= distSquared){
                    guilty++;
                    break;
                }
            }
        }
    }
    cout << n - guilty << endl;
    return 0;
}