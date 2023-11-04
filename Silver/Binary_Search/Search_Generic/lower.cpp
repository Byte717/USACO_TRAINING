#include <bits/stdc++.h>

using namespace std; 


int BinarySearchLower(vector<int> array, int target){
    int low = 0, high = array.size() - 1, mid;
    int ans = -1;
    while(low <= high){
        mid = ceil((low+high)/2);
        if(array[mid] < target){
            low = mid+1;
            ans = array[mid];
        }else{
            high = mid - 1;
        }
    }
    return ans;
}




int main(){
    vector<int> nums = {1,2,4,5,6};
    cout << BinarySearchLower(nums,3);


    return 0;
}