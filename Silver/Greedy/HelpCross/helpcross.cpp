#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define INF 1e9


using namespace std; 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("helpcross.in","r",stdin);//freopen("helpcross.out","w",stdout);
    int c, n; cin >> c >> n;
    vector<ll> chickens(c);
    vector<pair<ll,ll>> cows(n);
    for(int i = 0;i < c;i++){
        cin >> chickens[i];
    }
    for(int i = 0; i < n;i++){
        cin >> cows[i].first >> cows[i].second;
    } 
    sort(chickens.begin(),chickens.end());
    sort(cows.begin(),cows.end());
    ll ans = 0;
    for(auto& [s,e] : cows){
        if(chickens.empty()) break;
        auto it = lower_bound(all(chickens), s);
        if(*it <= e){
            ans++;
            chickens.erase(it);
        }
    }
    cout << ans << endl;
    return 0;
}