#include <bits/stdc++.h>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("maxcross.in","r",stdin);
    int n, k, b; cin >> n >> k >> b;
    vector<int> cows(n,false);
    int a;
    for(int i = 0; i < b;i++){
        cin >> a;
        cows[--a] = 1;
    }
    vector<int> prefix(n+1);
    prefix[0] = 0;
    for(int i = 0; i < n;i++){
        prefix[i]  = prefix[i-1] + (int)cows[i];
    }
    int low = 0, hi = 0, minNeeded = INT32_MAX;
    while(hi <= n-1){
        if(hi - low+1 < k){
            hi++;
        }else{
            int currentInRange = prefix[hi] - prefix[low-1];
            minNeeded = min(minNeeded,currentInRange);
            hi++;
            low++;
        }
    }
    cout << minNeeded << endl;


    return 0;
}