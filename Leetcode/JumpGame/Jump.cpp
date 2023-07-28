#include <bits/stdc++.h>

using namespace std;

bool canJump(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n,0);
    for(int i = 0; i < n;i++){
        if(nums[i] == 0) return dp[n-1] > 0;
        for(int j = i+1; j <= min(i+nums[i],n-1);j++){
            dp[j]++;
        }
    }
    return dp[n-1] > 0;
}


int main(){
    vector<int> nums = {2,3,1,1,4};
    cout << canJump(nums) << endl;
    return 0;
}