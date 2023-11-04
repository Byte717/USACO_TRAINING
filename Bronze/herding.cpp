#include <bits/stdc++.h>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("herding.in","r",stdin);
    freopen("herding.out","w",stdout);
    vector<int> cows(3);
    for(int i = 0; i < 3;i++){
        cin >> cows[i];
    }
    sort(cows.begin(),cows.end());
    if(cows[0] + 1 == cows[1] && cows[0] + 2 == cows[2] && cows[1] + 1 == cows[2]){
        cout << 0 << endl;
    }else if((cows[0]+2 == cows[1]) || (cows[1]+2 == cows[2])){
        cout << 1 << endl;
    }else{
        cout << 2 << endl;
    }
    cout << max(abs(cows[0] - cows[1]),abs(cows[1] - cows[2])) - 1 << endl;
    return 0;
}