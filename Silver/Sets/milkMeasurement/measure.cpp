#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

struct Data{
    ll day;
    ll cow;
    ll change;
}; 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("measurement.in","r",stdin);
    ll n; ll g; cin >> n >> g;
    vector<Data> measurements;
    map<ll,ll> cows;
    for(ll i = 0; i < n;i++){
        ll x; ll y,z;
        cin >> x >> y >> z;
        measurements.push_back(Data{x,y,z});
        cows[y] = g;
    }
    sort(all(measurements), [&](const Data& d1, const Data&d2){
        return d1.day < d2.day;
    });
    map<ll,ll> production{{g,n}};
    ll ans = 0;
    for(Data d : measurements){
        ll mlk = cows[d.cow];
        bool wasTop = (mlk == production.rbegin()->first);
        ll prevCount = production[mlk];
        production[mlk]--;

        if(production[mlk] == 0) { production.erase(mlk);}

        mlk += d.change;
        cows[d.cow] = mlk;
        production[mlk]++;

        bool isTop = (mlk == production.rbegin()->first);
        ll currCount = production[mlk];
        if(wasTop){
            if(isTop && currCount == prevCount) continue;
            ans++;
        }else if(isTop){
            ans++;
        }
    }
    freopen("measurement.out","w",stdout);
    cout << ans << endl;
    return 0;
}