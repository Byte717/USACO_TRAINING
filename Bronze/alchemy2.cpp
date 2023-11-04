#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("alchemy.in","r",stdin);
    int n, k; cin >> n; 
    vector<int> metals(n);
    for(int i = 0; i < n;i++) cin >> metals[i];
    cin >> k; 
    vector<vector<int>> recipies(k);
    for(int i = 0; i < k; i++){
    int metal, thingsNeeded; cin >> metal >> thingsNeeded;
    recipies[--metal].resize(thingsNeeded);
    for(int j = 0; j < thingsNeeded;j++){
        cin >> recipies[metal][j];
        recipies[metal][j]--;
    }
    }
    int ans = 0; 
    while(true){
    vector<int> consume(n);
    consume[n-1]++;
    if(recipies[n-1].size() == 0){
        break;
    }
    


    }

    return 0;
}