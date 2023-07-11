#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    freopen("angry.in","r", stdin);
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    auto reachesRight = [&](int position, int radius){
        auto it = upper_bound(arr.begin(),arr.end(),position);
        int idx = it - arr.begin();
        // position++;
        if(!(arr[idx] <= position + radius)){
            return false;
        }
        position = idx;
        while(radius != 0 && position < n){
            if(arr[position] <= arr[position-1] + radius){
                position++;
                radius--;
            }else{
                return false;
            }
        }
        return true;
    };
    auto reachesLeft = [&](int postition,int radius){
        auto it = lower_bound(arr.begin(),arr.end(),postition);
        int idx = it - arr.begin();
        if(!(arr[idx] >= postition - radius)){
            return false;
        }
        postition = idx;
        while(radius != 0 && postition >= 0){
            if(arr[postition] >= arr[postition+1]-radius){
                postition--;
                radius--;
            }else{
                return false;
            }
        }
        return true;
    };
    auto works = [&](int x){
        int startPos = arr[0], endPos = arr[n - 1], mid;
        while(startPos < endPos){
            mid = (startPos + endPos)/2;
            bool RR = reachesRight(mid,x);
            bool RL = reachesLeft(mid,x);
            if(RR && RL){
                return true;
            }
            if(!RL && RR){
                endPos = mid - 1;
            }else{  
                startPos = mid + 1;
            }
            if(!RR && !RL){
                return false;
            }
        }
        return false;         
    };
    cout << works(3) << endl;
    ll low = 0, high = 1e9, mid, ans = 1e9;
    while(low <= high){
        mid = low + (high-low)/2;
        if(works(mid)){
            ans = min(mid,ans);
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}