/*
ID: dhairya6
LANG: C++
PROG: milk
*/
#include <bits/stdc++.h>

using namespace std; 

int main(){
    ifstream cin("milk.in");
    ofstream cout("milk.out");
    int n, m; cin >> n >> m;
    vector<pair<int, int>> farmers(m);
    for(int i = 0; i < m;i++){
        cin >> farmers[i].first >> farmers[i].second;
    }
    sort(farmers.begin(),farmers.end());
    int ans = 0;
    for(int i = 0; i < m;i++){
        int currCost = 0;
        if(n >= farmers[i].second){
            currCost += farmers[i].second*farmers[i].first;
            n-= farmers[i].second;
        }else if(farmers[i].second > n){
            currCost += n*farmers[i].first;
            n -=  n;
        }
        ans += currCost;
        if(n == 0){
            break;
        }
    }
    cout << ans << endl;
    return 0;
}