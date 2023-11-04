#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream input("taming.in");
    int n; input >> n;
    vector<int> readings(n+1);
    for(int i = 1; i <= n; i++){
        input >> readings[i];
    } 
    vector<int> breakouts(n+1);
    fill(breakouts.begin(), breakouts.end(), 0);
    int minimumAmt = 1;
    breakouts[0] = 1;
    for(int i = 1; i <= n;i++){
        if(readings[i] != -1){
            breakouts[i-readings[i]] = 1;
            minimumAmt++;
        }
    }
    

    return 0;
}