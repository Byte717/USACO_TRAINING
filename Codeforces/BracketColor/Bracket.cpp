#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;
/*
Solution: the string can be segmented into parts that are a sequence, or the reverse of a sequence
then if there is just 1 big sequence: ((((())))), the answer is just 1 color
otherwise, you only need 2 colors to paint it.
Paint each segment 1 if it starts with ( and 2 if it starts with )

What I learned Bracket Coloring:
- Greedy involves grouping your input
*/

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> pref(n+1,0);
    for(int i = 0; i < n;i++){
        if(s[i] == '('){
            pref[i+1] = pref[i] + 1;
        }else{
            pref[i+1] = pref[i] - 1;
        }
    }
    if(pref.back() != 0){
        cout << -1 << endl;
    }else{
        if(*min_element(all(pref)) == 0 || *max_element(all(pref)) == 0){
            cout << 1 << endl;
            for(int i = 0; i < n;i++){
                cout << 1  << ' ';
            }
            cout << endl;
        }else{
            cout << 2 << endl;
            vector<int> ans;
            int curr =0;
            while(curr < n){
                int w = (s[curr] == '(') ? 1 : 2;
                do{
                    curr++;
                    ans.push_back(w);
                }while(pref[curr] != 0);
            }
            for(int i = 0; i < n;i++){
                cout << ans[i] << ' ';
            }
            cout << endl;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("Bracket.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}