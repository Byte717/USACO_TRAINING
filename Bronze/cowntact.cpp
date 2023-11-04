#include <bits/stdc++.h>

using namespace std; 

bool cow_ends_infected[101];
int cowx[251], cowy[251]; 


bool Consistent(int patient_zero, int K){


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("cowntact.in","r",stdin);
    int n,t; cin >> n >> t; string cows; cin >> cows;
    for(int i = 0; i < n;i++){
        cow_ends_infected[i] = cows[i]=='1';
    }
    for(int i = 0; i < t;i++){
        int time, x, y; cin >> time >> x >> y;
        cowx[t] = x;cowy[t] = y;
    }
    return 0;
}