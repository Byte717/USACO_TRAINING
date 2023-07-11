#include <bits/stdc++.h>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("cowdance.in","r",stdin);
    int n, tMax; cin >> n >> tMax;
    vector<int> times(n);
    for(int i = 0; i < n;i++) cin >> times[i];
    auto calcTime = [&](int k){
        int timeTaken = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> addList = times; 
        for(int i = 0; i < k;i++){
            pq.push(times[i]);
            addList.erase(addList.begin());
        }
        while(addList.size() != 0){
            timeTaken += max(0,abs(timeTaken-pq.top()));
            pq.pop();
            pq.push(addList[0]);
            addList.erase(addList.begin());
        }
        while(pq.size() != 0){
            timeTaken += max(0,abs(timeTaken-pq.top()));
            pq.pop();
        }
        return timeTaken;
     };

    int high = n, low = 1, sol = n;

     while(low <= high){
        int mid = low+(high-low)/2;
        int currTime = calcTime(mid);
        if(currTime > tMax){
            low = mid+1;
        }else{
            sol = min(sol,mid);
            high = mid - 1;
        }
    }
    cout << sol << endl;
    return 0;
}