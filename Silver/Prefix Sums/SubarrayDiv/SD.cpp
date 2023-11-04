#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("SD.in","r",stdin);
    int n; cin >> n;

    vector<ll> pref(n);
    ll a; cin >> a;
    pref[0] = a;
    for(int i = 1; i < n;i++){
        cin >> a;
        pref[i] = pref[i-1]+a;
    }
    for(int i = 0; i < n;i++){
        pref[i] %= n;
    }
    unordered_map<ll,ll> um;
    int ans = 0;
    for(int i = 0; i < n;i++){
        if(um.find(pref[i]) != um.end()){
            ans += um[pref[i]];
            um[pref[i]]++;
        }else{
            um.insert({pref[i],1});
        }
    }
    for(int i = 0; i < n;i++){
        if(pref[i] == 0) {ans++;}
    }
    cout << ans << endl;
    return 0;
}