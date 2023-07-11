#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("catDice.in","r",stdin);
    int t; cin >> t; 
    while(t--){
        int n, s, r; cin >> n >> s >> r;
        vector<int> dice(n,0);
        dice[n-1] = abs(s-r);
        int elementsLeft = n-1;
        for(int i = n-2; i >=0;i--){
            dice[i] = floor(r/elementsLeft);
            elementsLeft--;
            r-=dice[i];
        }
        sort(dice.begin(),dice.end());
        for(int i = 0; i < n;i++){
            cout << dice[i] << " ";
        }
        cout << endl;
    }



    return 0;
}