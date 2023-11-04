/*
ID: dhairya6
PROG: skidesign
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream cin("skidesign.in");
    ofstream cout("skidesign.out");
    int n; cin >> n;
    vector<int> hills(n);
    for(int i = 0; i < n;i++){
        cin >> hills[i];
    }

    int minCost = 1e6;
    for(int i = 0; i <= 83;i++){

        int cost = 0, x;

        for(int j = 0; j < n;j++){
            if(hills[j] < i){
                x = i - hills[j];
            }else if(hills[j] > i + 17){
                x = hills[j] - (i+17);
            }else{
                x = 0;
            }
            cost += x*x;
        }
        minCost = min(minCost, cost);
    }
    cout << minCost << endl;
    return 0;
}