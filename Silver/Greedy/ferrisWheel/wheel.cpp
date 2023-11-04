#include <bits/stdc++.h>

using namespace std; 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("wheel.in","r",stdin);
    int n,x; cin >> n >> x; 
    vector<int> arr(n);
    for(int y : arr){
        cin >> y >> endl;
    }
    sort(arr.begin(), arr.end());
    int i = 0, j = n - 1;
    vector<bool> paired(n, false);
    int ans = 0;
    while(i < j){
        if(arr[i]+arr[j]<=x){
            paired[i] = true;
            paired[j] = true;
            i++;j--;
            ans++;
        }else{
            j--;
        }
    }
    for(bool y : paired){
        ans+=(int)(y==false);
    }
    cout << ans << endl;
    return 0;
}