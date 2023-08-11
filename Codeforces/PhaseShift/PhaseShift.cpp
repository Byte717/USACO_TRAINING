#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

/*
solution: basically, we need to find the minimum lexographic string for s;
so, the first character is the first character that we can pick greedily
for each index, if no character is picked that is forward of it,
    iterate through each character
        if a character is not taken, 
            go through the circle and see if its a viable character


WHat I learned Phase Shift:
    - Lexographic implies greedy to take the smallest or largest character possible.

*/

void solve(){
    int n; cin >> n;
    string t; cin >> t;
    vector<int> chars(n);
    for(int i = 0; i < n;i++){
        chars[i] = t[i] - 'a';
    }
    vector<int> edge(26,-1), redge(26,-1);
    auto getPath = [&](int c){
        int len = 0;
        int curr = c;
        while(edge[curr] != -1){
            len++;curr = edge[curr];
        }
        return make_pair(curr,len);
    };


    for(int i = 0; i < n;i++){
        if(edge[chars[i]] == -1){
            for(int c = 0; c < 26;c++){
                if(redge[c] == -1){
                    auto [last, len] = getPath(c);
                    if(last != chars[i] || len == 25){
                        edge[chars[i]] = c;
                        redge[c] = chars[i];
                        break;
                    }
                }
            }
        }
        chars[i] = edge[chars[i]];
    }
    for(int i = 0; i < n;i++){
        t[i] = chars[i] + 'a';
    }
    cout << t << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("phase.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}