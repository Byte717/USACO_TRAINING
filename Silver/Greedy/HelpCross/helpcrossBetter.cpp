#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define all(x) begin(x),end(x)

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
    sort(all(cows));
    int ans = 0, cowIdx = 0;
    priority_queue<int> availableCows;
    for(int c : chickens){
        while(cowIdx < n && cows[cowIdx] <= c){
            availableCows.push(-cows[cowIdx].second);
            cowIdx++;
        }
        while(!availableCows.empty && -availableCows.top < c){
            availableCows.pop();
        }
        if(!availableCows.empty){
            ans++;
            availableCows.pop();
        }
    }
    cout << ans << endl;
    return 0;
}