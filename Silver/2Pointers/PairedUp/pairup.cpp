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
    vector<pair<ll,ll>> cows;

    for(int i = 0; i < n;i++){
        int x, y; cin >> x >> y;
        cows.push_back({y,x});
    }

    sort(cows.begin(),cows.end());
    ll left = 0, right = n-1, ans = -1;
    while(left <= right){
        if(cows[left].second == cows[right].second){
            ans = max(ans, cows[left].first+cows[right].first);
            left++;right--;
        }else if(cows[left].second < cows[right].second){
            ans = max(ans, cows[left].first+cows[right].first);
            cows[right].second -= cows[left].second;
            left++;
        }else{
            ans = max(ans, cows[left].first+cows[right].first);
            cows[left].second -= cows[right].second;
            right--;
        }
    }
    cout << ans << endl;
    return 0;
}