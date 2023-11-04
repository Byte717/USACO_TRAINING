#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("sleepy.in","r",stdin);
    int n; cin >> n; 
    vector<int> cows(n);
    for(int i = 0; i < n;i++){
        cin >> cows[i];
    }
    int ans = n - 1; 
    for(int i = n - 1; i >=1;i--){
        if(cows[i] > cows[i-1]) ans--;
        else break;
    }
    cout << ans << endl;
    return 0;
}