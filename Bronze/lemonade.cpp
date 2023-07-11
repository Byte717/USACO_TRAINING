#include <bits/stdc++.h>
#define ll long long

using namespace std; 


int main(){
    freopen("lemonade.in", "r", stdin); // taking input
    freopen("lemonade.out", "w", stdout);
    int N; cin >> N;
    vector<ll> cows(N);  // make an array to sort
    for(auto& x : cows){
        cin >> x; 
    }
    sort(cows.begin(), cows.end(), greater<int>()); // sort backwards
    ll cowsCount = 0;
    for(auto& x : cows){
        if(cowsCount <= x){
            cowsCount++;
        }else{
            break;
        }
    }
    cout << cowsCount << endl;


    return 0;
}