#include <bits/stdc++.h>

using namespace std;


bool subArrayWorks(vector<int>& nums, int target, int size){
    int currentSum = 0;
    int low = 0, high = 0; 
    while(high < nums.size()){
        if(currentSum >= target){
            return true;
        }
        currentSum += nums[high];
        if(high - low + 1 == size){
            low++;
            high++;
            currentSum -= nums[low-1];
        }else{
            high++;
        }
    }
    return false;
}

int minSubArrayLen(int target, vector<int> nums) {
    int low = 0, high = nums.size(), mid, ans = -1;
    while(low < high){
        mid = (low + high)/2;
        if(subArrayWorks(nums,target, mid)){
            ans = mid;
            high = mid - 1; 
        }else{
            low = mid + 1;
        }
    }
    return (ans == -1) ? 0 : ans;
}

int main(){
    cout << minSubArrayLen(7,{2,3,1,2,4,3});

}