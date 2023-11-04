#include <bits/stdc++.h>

using namespace std; 


void solve(){
    int n; cin >> n; 
    vector<int> array(n);
    for(int i = 0; i < n; i++) cin >> array[i];
    vector<int> skips(n, 0);
    bool badPlayer = true;
    int turnsPassed = 0;
    for(int i = 0; i < n;i++){
        if(turnsPassed == 2){
            badPlayer = !(badPlayer);
            turnsPassed = 0;
        }
        if(turnsPassed == 1 && badPlayer && array[i] == 1){
            badPlayer = false;
            turnsPassed = 0;
        }
        if(badPlayer && array[i] == 1){
            if(i == 0){
                skips[i] = 1;
            }else{
                skips[i] = skips[i-1]+1;
            }
        }else{
            if(i == 0){
                skips[i] = 0;
            }else{
                skips[i]= skips[i-1];
            }
        }
        turnsPassed++;
    }
    cout << skips[n-1] << endl;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("test.in","r",stdin);
    int t;
    cin >> t; 
    while(t--){
        solve();
    }

    return 0;
}