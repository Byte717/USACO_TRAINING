#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("AB.in","r",stdin);
    int pts[26];
    for(int i = 0; i < 26;i++){
        cin >> pts[i];
    }
    string s; cin >> s;
    int n = s.size();
    vector<int> pref(n+1,0);
    for(int i = 0; i < n;i++){
        pref[i+1] = pts[s[i]-'a'] + pref[i];
    }
    vector<vector<int>> occ(26);
    for(int i = 0; i < n;i++){
        occ[s[i]-'a'].push_back(i);
    }
    int ans = 0;
    for(int letter = 0; letter < 26;letter++){
        if(occ[letter].size() == 0) continue;
        for(int i = 0; i < occ[letter].size()-1;i++){
            for(int j = i+1;j < occ[letter].size();j++){
                ans = max(ans, pref[occ[letter][j]] - pref[occ[letter][i] -1]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}