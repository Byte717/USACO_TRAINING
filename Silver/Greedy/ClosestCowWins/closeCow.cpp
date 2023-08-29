#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

struct Group{
    ll nhojPos = -1;
    ll before = 0, after = 0;
    ll total = 0;
};


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("closeCow.in","r",stdin);
    ll k, m, n; cin >> k >> m >> n;
    vector<pair<ll,ll>> patches(k);
    for(auto &[p,t] : patches){
        cin >> p >> t;
    }
    vector<ll> cows(m);
    for(int i = 0; i < m;i++){
        cin >> cows[i];
    }
    sort(all(cows));
    sort(all(patches));
    vector<Group> groups(m);
    for(int i = 0; i < m;i++){
        groups[i].nhojPos = cows[i];
    }
    auto makeGroups = [&](){
        for(auto &[p,t] : patches){
            auto it = lower_bound(all(cows), p);
            int idxAfter = it - cows.begin(), idxBefore = prev(it) - cows.begin();
            if(it == cows.end()){
                if(p > cows[idxBefore]){
                    groups[idxBefore].after += t;
                }else{
                    groups[idxBefore].before += t;
                }
                groups[idxBefore].total += t;
            }else if(idxAfter == idxBefore){
                if(p > cows[idxAfter]){
                    groups[idxAfter].after += t;
                }else{
                    groups[idxAfter].before += t;
                }
                groups[idxAfter].total += t;
            }else{
                if(abs(p - cows[idxAfter]) == abs(p - cows[idxBefore])){
                    if(p > cows[idxAfter]){
                        groups[idxAfter].after += t;
                    }else{
                        groups[idxAfter].before += t;
                    }
                    groups[idxAfter].total += t;
                    if(p > cows[idxBefore]){
                        groups[idxBefore].after += t;
                    }else{
                        groups[idxBefore].before += t;
                    }
                    groups[idxBefore].total += t;
                }else if(abs(p - cows[idxAfter]) < abs(p - cows[idxBefore])){
                    if(p > cows[idxAfter]){
                        groups[idxAfter].after += t;
                    }else{
                        groups[idxAfter].before += t;
                    }
                    groups[idxAfter].total += t;
                }else{
                    if(p > cows[idxBefore]){
                        groups[idxBefore].after += t;
                    }else{
                        groups[idxBefore].before += t;
                    }
                    groups[idxBefore].total += t;
                }
            }
        }
    };
    makeGroups();
    sort(rall(groups), [](const Group&g1, const Group&g2){return g1.total < g2.total;});
    ll total = 0;
    ll remain = 0;
    for(int i = 0; i < n;i++){
        if(i == 0){
            if(groups[i].after > groups[i].before){
                total += groups[i].after;
            }else{
                total += groups[i].before;
            }
        }
    }
    cout << total << endl;
    return 0;
}