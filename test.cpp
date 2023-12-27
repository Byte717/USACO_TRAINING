#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// #pragma GCC optimize("O3","unroll-loops")
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

class grp{
    public:
        ll weight, num; 
};

bool cmp(grp &a, grp &b){  
    if(a.weight == b.weight) return a.num < b.num;
    return a.weight < b.weight;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("prob2.in","r",stdin);
    int n;ll m,k; cin >> n >> m >> k;
    vector<grp> cows(n);
    ll tot = 0;
    for(int i = 0; i < n;i++){
        ll w, a; cin >> w >> a;
        cows[i] = {w,a};
        tot += a;
    }
    sort(all(cows),cmp);
    reverse(all(cows));

    ll towersUsed = 0;
    ll cowsUsed = 0;
    map<ll, ll> tops;
    // for(int i = 0; i < n;i++){
    //     if(i == 0){
    //         tops[cows[i].weight] = cows[i].num;
    //         cowsUsed += cows[i].num;
    //         towersUsed += cows[i].num;
    //     }else{
    //         auto it = tops.lower_bound(cows[i].weight);
    //         while(it != tops.begin() && it->first + k < cows[i].weight){
    //             it--;
    //         }
    //         if(it == tops.end()){
    //             if(towersUsed < m){
    //                 tops[cows[i].weight] = m-towersUsed;
    //             } // tops[i] = num towers with i as the topmost weight
    //         }else{
    //             if(cows[i].num > it->second){
    //                 ll originalA = it->second, originalW = it->first;
    //                 tops.erase(it);
    //                 tops[cows[i].weight] = min(cows[i].num, m);
    //                 towersUsed += cows[i].num - originalA;
    //             }else if(cows[i].num  < it->second){ // number of towers with weight just Greater
    //                 ll originalA = it->second, originalW = it->first;
    //                 tops.erase(it);
    //                 tops[cows[i].weight] = min(cows[i].num, m);
    //                 tops[originalW] = originalA - cows[i].num;
    //             }else{
    //                 tops.erase(it);
    //                 tops[cows[i].weight] = min(cows[i].num, m);
    //             }
    //             cowsUsed += min(cows[i].num, m);

    //         }
    //     }
    // }

    for(int i = 0; i < n;i++){
        ll mxPossibleNew = m - towersUsed;
        if(i==0){
            tops[cows[i].weight] = min(mxPossibleNew,cows[i].num);
            towersUsed += min(mxPossibleNew,cows[i].num);
            cowsUsed += min(mxPossibleNew,cows[i].num);
        }else{
            auto it = tops.lower_bound(cows[i].weight);
            while(it != tops.end() && it->first - cows[i].weight < k){
                it++;
            }
            if(it == tops.end()){ // create another tower
                tops[cows[i].weight] = min(mxPossibleNew, cows[i].num);
                towersUsed += min(mxPossibleNew,cows[i].num);
                cowsUsed += min(mxPossibleNew,cows[i].num);
                continue;
            }
            ll towerHighestType = it->second;
            ll highWeight = it->first;
            if(highWeight - cows[i].weight < k){
                continue;
            }
            if(cows[i].num > towerHighestType){ // make the max amount of new Towers possible
                cowsUsed += towerHighestType + mxPossibleNew;
                if(mxPossibleNew == 0){
                    continue;
                }
                tops.erase(it);
                tops[cows[i].weight] = towerHighestType + mxPossibleNew; 
            }else if(cows[i].num < towerHighestType){ // no new Towers Made
                cowsUsed += cows[i].num;
                tops[it->first] -= cows[i].num;
                tops[cows[i].weight] = cows[i].num;

            }else{
                tops.erase(it);
                tops[cows[i].weight] = towerHighestType;
                cowsUsed += towerHighestType;
            }
        }
    }
    cout << cowsUsed << endl;
    return 0;
}