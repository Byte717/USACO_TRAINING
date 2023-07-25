#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}
void solve(){
    int n; cin >> n;
    vector<ll> pref(n-1);
    for(int i = 0; i < n-1;i++){
        cin >> pref[i];
    }
    vector<ll> arr;
    for(int i = 1; i < n-1;i++){
        arr.push_back(pref[i]-pref[i-1]);
    }
    for(int i = 0; i < arr.size();i++){
        
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("pref.in","r",stdin);
    int t; cin >> t;
    while(t--){solve();}
    return 0;
}