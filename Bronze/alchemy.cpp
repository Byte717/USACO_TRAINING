#include <bits/stdc++.h>

using namespace std; 
vector<int> metals;
vector<vector<int>> recipes;


bool canMakeMore(int WhatMetal){

    if(recipes[WhatMetal].size() == 0){
        return false;
    }
    for(int i = 0; i < recipes[WhatMetal].size();i++){

    }
    
    if(metals[WhatMetal] == 0) return 0;

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("alchemy.in", "r",stdin);
    int n; cin >> n; 
    metals = vector<int>(n);
    for(int i = 0; i < n; i++) cin >> metals[i];
    int k; cin >> k;
    recipes = vector<vector<int>>(n);
    for(int i = 0; i < k;i++){
        int metal, numNeeded; cin >> metal >> numNeeded;
        metal--;
        for(int j = 0; j < numNeeded;j++){
            int x; cin >> x; x--;
            recipes[metal].push_back(x);
        }
    }
    if(recipes[n-1].size() == 0){
        cout << recipes[n-1] << endl;
        return 0;
    }


    return 0;
}