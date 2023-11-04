#include <bits/stdc++.h>
using namespace std;

int BinarySearchRotated(vector<int>& nums, int target){
    int low = 0, high = nums.size() - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[mid] < nums[high]){
            if(target >= nums[mid] && target <= nums[high]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }else{
            if(target >= nums[low] && target <= nums[mid]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
    }
    return -1;
}


int main(){
    vector<int> nums = {6, 7, 1, 2, 3, 4, 5};
    int target = 6;
    cout << BinarySearchRotated(nums,target);


    return 0;
}