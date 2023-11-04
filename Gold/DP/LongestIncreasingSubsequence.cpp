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

void fasterLis(int n, vector<ll> a){
    vector<int> dp;
    for(int i = 0; i < n;i++){
        int pos = lower_bound(all(dp), a[i]) - dp.begin();
        if(pos == dp.size()){
            dp.push_back(a[i]);
        }else{
            dp[pos] = a[i];
        }
    }
    cout << dp.size() << endl;
}


int main(){
    Solution obj1;
    vector<int> arr = {7, 3, 5, 3, 6, 2, 9, 8};
    cout << obj1.lengthOfLIS(arr) << endl;

}