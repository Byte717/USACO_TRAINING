#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


/*
observations:
    - when there is an even number of c, the answer is No
    - when there is an even number of a character, then it can be deleted completly
    - if the number of c's is zero, then it requires an odd number of some other character to 
    - however, if there is only 1 character, thats not a c, then the answer is a no 

solution: the parity of characters matter. FOr instance:
    - if c+w  or c + o are odd, then the answer is yes, since c can be isolated. otherwise, there will be multiple c's
    - other thing to note, if o + w are even, then the answer can be yes, otherwise, we can have a character left


what I learned Cow Operations:
    - look for relationships between tasks. for example,in this problem, i need to know that for make a substring just c, that c amount depends on o and w, and some combo of the 2.

*/
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    string s; cin >> s;
    int n = s.length();
    vector<vector<int>> pref(3, vector<int>(n+1,0));

    auto update = [&](int x, int i){
        pref[x][i+1] = pref[x][i];
    };

    for(int i = 0; i < n;i++){
        if(s[i] == 'C'){
            pref[0][i+1] = pref[0][i] + 1;
            update(1,i);
            update(2,i);
        }else if(s[i] == 'O'){
            update(0,i);
            pref[1][i+1] = pref[1][i] + 1;
            update(2,i);
        }else if(s[i] == 'W'){
            update(0,i);
            update(1,i);
            pref[2][i+1] = pref[2][i] + 1;
        }
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        vector<int> counts(3);
        for(int i = 0; i < 3;i++){
            counts[i] = pref[i][r] - pref[i][l-1];
        }
        if(((counts[0] + counts[1]) % 2 == 0 || (counts[0] + counts[2])%2 == 0) || (counts[1] + counts[2]) %2 != 0){
            cout << "N";
        }else{
            cout << "Y";
        }
    }
    cout << endl;
    return 0;
}