#include <bits/stdc++.h>

using namespace std; 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for(int i = 1; i < nums.size();i++){
            if(nums[i-1] < nums[i]){
                dp[i] = dp[i-1]+1;
            }else{
                dp[i] = max(dp[i],dp[i-1]);
            }
        }
        return dp[nums.size()-1];
    }
};

int main(){
    Solution obj1;
    vector<int> arr = {0,1,0,3,2,3};
    cout << obj1.lengthOfLIS(arr) << endl;

}