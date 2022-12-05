#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream input("div7.in");
    long long n; input >> n;
    vector<long long> nums(n+1);
    fill(nums.begin(), nums.end(), 0);
    for(int i = 1; i <= n; i++)input >> nums[i];
    for(int i = 1; i <= n;i++)nums[i] = nums[i] + nums[i-1];
    long long maxNum = INT64_MIN, curr = 0;
    for(int i = 1; i <= n - 1; i++) for(int j = i+1; j <= n; j++){
        if((nums[j] - nums[i-1]) % 7 == 0){
            curr = j - i + 1;
            maxNum = max(maxNum, curr);
            curr = 0;
        }
    }
    cout << maxNum << endl;
    return 0;
}