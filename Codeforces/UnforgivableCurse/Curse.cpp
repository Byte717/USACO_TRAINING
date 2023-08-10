#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

/*
solution: since the distance between 2 positions can be k or k + 1, we can look at positions where position i's swap can be inside n
then, for the positions, keep a track of what is needed and what is available using cnt
if the amount available for all chars is == to the amount needed, then it is ok
*/
void solve(){
    int n, k; cin >> n >> k;
    string s, t; cin >> s >> t;
    vector<int> cnt(26,0);
    bool works = true;

    for(int i = 0; i < n;i++){
        if(i >= k || i + k < n){
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']--;
        }else{
            works = works && (s[i] == t[i]);
        }
    }
    int x = 0;
    for(int i = 0; i < 26;i++){
        if(cnt[i] == 0){
            x++;
        }
    }
    if(works && x == 26){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}