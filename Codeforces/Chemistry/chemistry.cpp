#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> freq(26);
    for(int i = 0; i < n;i++){
        freq[s[i]-'a']++;
    }
    int odds = 0;
    for(int i = 0; i < 26;i++){
        if(freq[i] % 2 != 0){
            odds++;
        }
    }
    if(odds > k){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }

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