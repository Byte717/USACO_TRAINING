#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> subsets(vector<ll> &arr, int n){
    vector<vector<ll>> ret;
    for(int i = 0; i < (1 << n);i++){
        vector<ll> curr;
        for(int j = 0; j < n;i++){
            if((j & (1 << j))){
                curr.push_back(arr[j]);
            }
        }
        ret.push_back(curr);
    }
    return ret;
}