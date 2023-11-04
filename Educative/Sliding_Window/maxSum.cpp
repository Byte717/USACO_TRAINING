#include <bits/stdc++.h> 


using namespace std; 

int slidingWindowSum(vector<int> array, int windowSize){
    int lowIdx = 0, highIdx = 0; 
    int maxSum = INT16_MIN, currSum = 0; 
    for(int i = 0; i < array.size();i++){
        if(highIdx - lowIdx == windowSize){
            maxSum = max(currSum,maxSum);
            currSum-=array[lowIdx];
            currSum+=array[highIdx];
            highIdx++;
            lowIdx++;

        }else{
            currSum+=array[highIdx];
            highIdx++;
        }
    }
    return maxSum;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v1 = {4,2,7,9,5,6};
    cout << slidingWindowSum(v1,2);
    return 0;
}