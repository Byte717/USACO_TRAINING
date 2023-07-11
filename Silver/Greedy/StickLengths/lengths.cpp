#include <bits/stdc++.h>

using namespace std; 




int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("stick.in","r",stdin);
    int n; cin >> n;
    vector<long long> arr(n);
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    long long median = -1;
    if(n%2 == 0){
        median = arr[n / 2];
    }else{
        median = (arr[(n - 1) / 2] + arr[n / 2]) / 2;
    }
    int cost = 0;
    for(int i = 0; i < n;i++){
        cost+=abs(median-arr[i]);
    }
    cout << cost << endl;
    return 0;
}