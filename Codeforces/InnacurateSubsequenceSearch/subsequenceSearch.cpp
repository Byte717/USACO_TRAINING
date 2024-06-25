#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// #pragma GCC optimize("O3","unroll-loops")
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

void solve(){
    int n, m,k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    multiset<int> todo, done, extra;
    for(int i = 0; i < m;i++){
        cin >> b[i];
        todo.insert(b[i]);
    }
    for(int i = 0; i < m;i++){
        if(todo.find(a[i]) != todo.end()){
            todo.erase(todo.find(a[i]));
            done.insert(a[i]);
        }else{
            extra.insert(a[i]);
        }
    }
    int ans = (done.size() >= k);
    for(int right = m; right < n;right++){
        int toRemove = a[right-m];
        if(extra.find(toRemove) != extra.end()){
            extra.erase(extra.find(toRemove));
        }else if(done.find(toRemove) != done.end()){
            done.erase(done.find(toRemove));
            todo.insert(toRemove);
        }
        if(todo.find(a[right]) != todo.end()){
            todo.erase(todo.find(a[right]));
            done.insert(a[right]);
        }else{
            extra.insert(a[right]);
        }
        ans += (done.size() >= k);
    }
    cout << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("subseq.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}