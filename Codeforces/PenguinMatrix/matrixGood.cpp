#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("matrix.in","r",stdin);
    int n, m, d; cin >> n >> m >> d;
    vector<ll> arr;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            int x; cin >> x;
            arr.push_back(x);
        }
    }
    sort(all(arr));
    int cp = 0;
    if(arr.size() % 2 == 0){
        cp = (arr.size()/2 - 1);
    }else{
        cp = (arr.size()/2);
    }
    int res = 0;
    for(int i = 0; i < arr.size();i++){
        if(i == cp){
            continue;
        }
        int z = abs(arr[cp] - arr[i]);
        if(z % d != 0){
            cout << -1 << endl;
            return 0;
        }
        res += (z/d);
    }
    cout << res << endl;
    return 0;
}