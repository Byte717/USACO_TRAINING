#include <bits/stdc++.h>
using namespace std; 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("lemonade.in","r",stdin);
    int n; cin >> n; 
    vector<int> cows(n);
    for(int i = 0; i < n;i++)cin >> cows[i];
    sort(cows.begin(),cows.end(), greater<int>());
    int cowCount = 0;
    for(int i = 0; i < n; i++){
        if(cows[i] >= i){
            cowCount++;
        }else{
            break;
        }
    }
    cout << cowCount << endl;

    return 0;
}