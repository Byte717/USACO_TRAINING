#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

/*
solution, count the number of positions that do not match. 
during updates, use a queue to keep track of what is covered.
the strings are equal if at any momment the bad count is 0

What I learned charBlock: 
-string hashing
-Queues can be used for queries that last for a time

Alternate solution:
Hash the string, and for 3 queries the answer is the hash - the hash of the ignored chars



*/

void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int bad = 0; 
    for(int i = 0; i < n;i++){
        if(s1[i] != s2[i]){
            bad++;
        }
    }
    int t, q; cin >> t >> q;
    queue<pair<int,int>> blocked;
    for(int i = 0; i < q;i++){
        while(!blocked.empty() && blocked.front().first == i){
            if(s1[blocked.front().second] != s2[blocked.front().second]){
                bad++;
            }
            blocked.pop();
        }
        int type; cin >> type;
        if(type == 1){
            int pos; cin >> pos;
            pos--;
            if(s1[pos] != s2[pos]){
                bad--;
            }
            blocked.emplace(i+t, pos);
        }else if(type == 2){
            int num1, pos1, num2, 
        }else{
            cout << (!bad ? "YES":"NO") << endl;
        }
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