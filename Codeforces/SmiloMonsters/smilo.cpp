#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


void _2pt(vector<int> a, int n){
    int low = 0, high = n-1;
    int x = 0;
    int ans = 0;
    while(low < high){
        if(x >= a[high]){
            high--;
            x = 0;
            ans++;
        }
        x += a[low];
        ans += a[low];
        low++;
    }
    cout << ans << endl;
}


void accGreedy(vector<int> a, int n){
    int ans = 0, x = 0;
    for(int i = 0; i < n;i++){
        if(x >= a[i]){
            a[i] -= x;
            ans++;
        }else{
            ans += a[i];
            x += a[i];
        }
    }
    cout << ans << endl;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    sort(all(a));

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}