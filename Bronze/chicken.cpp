#include <bits/stdc++.h>
#define ll long long


using namespace std; 

int main(){
    freopen("helpcross.in", "r", stdin);
    int C, N; cin >> C >> N;
    vector<ll> chickens(C);
    vector<pair<ll, ll>> cows(N);
    for(auto& x : chickens) cin >> x;
    for(int i = 0; i < N; i++){
        ll x, y;
        cin >> x >> y; 
        cows[i] = make_pair(x, y);
    }
    vector<bool> chickensUsed(C);
    fill(chickensUsed.begin(), chickensUsed.end(), false);
    vector<bool> cowsUsed(N); 
    fill(cowsUsed.begin(), cowsUsed.end(), false);
    sort(chickens.begin(), chickens.end());
    sort(cows.begin(), cows.end());
    ll ans = 0;
    for(int i = 0; i < C;i++){
        for(int j = 0; j < N;j++){
            if(cows[j].first <= chickens[i] && chickens[i] <= cows[j].second){
                if(!cowsUsed[j] && !chickensUsed[i]){
                    ans++;
                    cowsUsed[j] = true;
                    cowsU
                }
            }
        }
    }
    

    return 0; 
}