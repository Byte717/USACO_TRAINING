#include <bits/stdc++.h>

using namespace std; 

int main(){
    freopen("outofplace.in","r",stdin);
    int N; cin >> N; 
    vector<int> arr1(N);
    vector<int> arr2(N);
    for(int i = 0; i < N;i++){
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }
    sort(arr1.begin(),arr1.end());
    int ans = 0; 
    for(int i = 0; i < N;i++){
        if(arr1[i] != arr2[i]) ans++;
    }
    cout << ans - 1 << endl;
    return 0;
}