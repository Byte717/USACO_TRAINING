#include <bits/stdc++.h>

using namespace std;


int minMoves(vector<int> arr){
    int maxSorted = 1;
    int tempSorted = 0;
    vector<bool> counted(arr.size(),false);
    for(int i = 1; i < arr.size();i++){
        if(arr[i] == arr[i-1] + 1 || arr[i] == arr[i-1] + 2){
            if(counted[i-1] || counted[i]){
                tempSorted++;
            }else{
                tempSorted+=2;
            }
            counted[i] = true;
            counted[i-1] = true;
        }else{
            maxSorted = max(maxSorted, tempSorted);
            tempSorted = 0;
        }
    }
    maxSorted = max(maxSorted, tempSorted);
    return arr.size() - maxSorted; 

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("herding.in","r",stdin);
    int n; cin >> n;
    vector<int> cows(n);
    for(int i = 0; i < n;i++) cin >> cows[i];
    sort(cows.begin(),cows.end());
    
    cout << minMoves(cows)  << endl << max(cows[n-2]-cows[0], cows[n-1] - cows[1]) - (n-2) << endl;
    return 0;
}