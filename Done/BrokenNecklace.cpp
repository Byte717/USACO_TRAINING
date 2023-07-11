/*
ID: dhairya6
PROG: beads
LANG: C++
*/

#include <bits/stdc++.h>


using namespace std; 


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    int n; cin >> n; 
    string s; cin >> s;
    s = s+s;
    int res = -1;
    for(int i = 0; i < n; i++){
        char c = s[i];
        int current = 0;
        int j = i;
        for (int state = c!='w'; state <= 2; state++) {
            for (; j < n + i && (s[j] == c || s[j] == 'w'); j++) {
                current++;
            }
            c = s[j];
        }
        res = max(res, current);
    }
    cout << res << endl;
    

    return 0;
}