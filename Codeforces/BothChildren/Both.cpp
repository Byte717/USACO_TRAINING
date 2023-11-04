#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

/*
    let dp[i] represent the maximum frogs caught on the ith distance.
    first, the a[i] > n is irrelevant
    we keep a track of how many times a jump occurance appears in a map, 
    then for each unique frog, we jump through and add occ[a[i]] to dp[j];

    What I learned 

*/

void solve2(){
    int n; cin >> n;
    vector<int> a;
    unordered_map<int,int> occ;
    for(int i = 0; i < n;i++){
        int x; cin >> x;
        if(x <= n){
            if(occ.find(x) == occ.end()){
                a.push_back(x);
            }
            occ[x]++;
        }
    }
    vector<int> dp(n+1,0);
    for(int i = 0; i < a.size();i++){
        for(int j = 0; j <= n;j+=a[i]){
            dp[j]+=occ[a[i]];
        }
    }
    cout << *max_element(dp.begin()+1,dp.end()) << endl;
}


void solve(){
    int n; cin >> n;
    vector<ll> a(n), cnt(n+1,0);
    for(int i = 0; i < n;i++){
        cin >> a[i];
        if(a[i] <= n) cnt[a[i]]++;
    }
    vector<int> MX(n+1,0);
    // sort(all(a));
    for(int i = 1; i <= n;i++){
        for(int j = i;j <=n;j+=i){
            MX[j] += cnt[i];
        }
    }
    cout << *max_element(all(MX)) << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("Both.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve2();
    }
    return 0;
}