#include <bits/stdc++.h>
#define INF 1e18
// #define MOD 1e9+7

typedef long long ll;

using namespace std; 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("pairup.in","r",stdin);
    freopen("pairup.out","w",stdout);
    int n; cin >> n;
    vector<ll> cows;
    for(int i = 0; i < n;i++){
        ll x,y; cin >> x >> y;
        for(int j = 0; j < x;j++){
            cows.push_back(y);
        }
    }
    sort(cows.begin(), cows.end());
    ll left = 0, right = cows.size()-1, ans = -1;
    while(left < right){
        ans = max(ans,cows[left] + cows[right]);
        left ++; right --;
    }
    cout << ans << endl;
    return 0;
}