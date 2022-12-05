#include <bits/stdc++.h>

using namespace std;

ifstream input("sleepInClass.txt");

void solve(){
    int n;input>>n; 
    int sumA = 0;int nums[n];
    for(int i = 0;i<n;i++){
        input>>nums[i];sumA+=nums[i];
    }
    for(int r = n; r >= 1;r--){
        if(sumA % r == 0){
            int target = sumA / r, currSum = 0; 
            bool ok = true; 
            for(int i = 0; i < n;i++){
                currSum+=nums[i];
                if(currSum > target){
                    ok = false;
                    break;
                }
                if(currSum == target){
                    currSum = 0; 
                }
            }
            if(ok){
                cout << n - r << endl;
                return;
            }
        }
    }
}

int main(){
    int t;input>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
    return 0;
}



