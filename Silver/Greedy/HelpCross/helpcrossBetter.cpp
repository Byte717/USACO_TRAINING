#include <bits/stdc++.h>
#define ll long long
#define INF 1e9


using namespace std; 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("helpcross.in","r",stdin);freopen("helpcross.out","w",stdout);
    int c, n; cin >> c >> n;
    vector<ll> chickens(c);
    vector<pair<ll,ll>> cows(n);
    for(int i = 0;i < c;i++){
        cin >> chickens[i];
    }
    for(int i = 0; i < n;i++){
        cin >> cows[i].first >> cows[i].second;
    }
    return 0;
}