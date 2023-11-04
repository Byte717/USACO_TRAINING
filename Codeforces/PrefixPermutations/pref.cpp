#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;
int n; 
bool isPermutation(vector<ll> arr){
    for(int i = 0; i < n;i++){
        if(arr[i] <= 0 || arr[i] > n){
            return false;
        }
    }
    return true;
}

vector<ll> prefToArr(vector<ll> &pref){
    vector<ll> ret(n);
    ret[0] = pref[0];
    for(int i = 1; i < n;i++){
        ret[i] = pref[i] - pref[i-1];
    }
    return ret;
}


void solve(){
    cin >> n;
    vector<ll> pref(n-1);
    for(int i = 0; i < n-1;i++){
        cin >> pref[i];
    }
    ll x = n*(n+1)/2;
    if(pref.back() != x){
        pref.push_back(x);
        vector<ll> arr = prefToArr(pref);
        if(isPermutation(arr)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        return;
    }
    map<ll,ll> m;
    m[pref[0]]++;
    for(int i = 1; i < n-1;i++){
        m[pref[i]-pref[i-1]]++;
    }
    vector<int> cntCt1;
    for(auto i : m){
        if(i.second > 1){
            cntCt1.push_back(i.first);
        }
    }
    if(cntCt1.size() > 1){
        cout << "NO" << endl;
        return;
    }
    if(cntCt1.size() == 1){
        ll x1 = cntCt1[0];
        if(m[x1] > 2){
            cout << "NO" << endl;
            return;
        }
    }
    vector<int> cnt0;
    for(int i = 1; i <=n;i++){
        if(m[i] == 0){
            cnt0.push_back(i);
        }
    }
    if(cnt0.size() != 2){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("pref.in","r",stdin);
    int t; cin >> t;
    while(t--){solve();}
    return 0;
}