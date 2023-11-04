#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;




// struct  cmp
// {
//     bool operator()(const pair<ll,int> &p1, const pair<ll,int> &p2) const {
//         if(p1.first == p2.first) return p1.second > p2.second;
//         return p1.first < p2.first;
//     }
// };


// void solve(){
//     int n; ll k; cin >> n >> k;
//     set<pair<ll,int>,cmp> idxSet;
//     for(int i = 0; i < n;i++){
//         ll a; cin >> a;
//         if(a!=k) idxSet.insert({a%k,i});
//         else idxSet.insert({a,i});
//     }
//     while(!idxSet.empty()){
//         ll hp = (*prev(idxSet.end())).first; int idx = (*prev(idxSet.end())).second;
//         idxSet.erase(prev(idxSet.end()));
//         hp -= k;
//         if(hp <= 0){
//             cout << idx+1 << ' ';
//         }else{
//             idxSet.insert(make_pair(hp,idx));
//         }

//     }
//     cout << endl;
// }
void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int &i : a){
        cin >> i;
        if(i%k == 0){
            i = k;
        }else{
            i %= k;
        }
    }
    vector<int> ord(n);
    iota(all(ord),0);
    stable_sort(all(ord),[&](int i,int j){return a[i] > a[j];});
    for(auto &x : ord){
        cout << x+1 << ' ';
    }
    cout << endl;
}



int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("monsters.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}