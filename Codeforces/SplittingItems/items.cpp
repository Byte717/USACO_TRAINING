#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define debug

#ifndef debug
    #pragma GCC optimize("O3","unroll-loops")
    #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#endif

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

void solve(){
    int n,k; cin >> n >> k;
    vector<int> items(n);
    for(int i = 0; i < n;i++){
        cin >> items[i];
    }
    sort(rall(items));
    bool AliceTurn = true;
    int aliceScore = 0, bobScore = 0;
    for(int i = 0; i < n;i++){
        if(AliceTurn){
            aliceScore+= items[i];
        }else{
            int diff = items[i-1] - items[i];
            int take = min(k, diff);
            k -= take;
            bobScore += (items[i] + take);
        }
        AliceTurn = !AliceTurn;
    }
    cout << aliceScore - bobScore << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("items.in","r",stdin);
    #ifdef LOCAL
	auto _clock_start = chrono::high_resolution_clock::now();
    #endif 
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    #ifdef LOCAL
    cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
        chrono::high_resolution_clock::now()
            - _clock_start).count() << "ms." << endl;
    #endif
    return 0;
}