#include <bits/stdc++.h>
#define INF 1e18
#define mod 1e9+7

typedef long long ll;

const double MAX_ERROR = 1e-7;

using namespace std; 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("meetplace.in","r",stdin);
    int n; cin >> n;
    double low = 0, high = 0, mid;
    vector<double> location(n), speed(n);
    for(int i = 0; i < n;i++){
        cin >> location[i];
        high = max(high, location[i]);
    }
    for(int i = 0; i < n;i++){
        cin >> speed[i];
    }

    double min_ans = (double)INT_MAX;
    bool LeftMax = false, RightMax = false;
    auto get_time = [&](int x){
        double MaxTime = 0;
        for(int i = 0; i < n;i++){
            if(location[i] == x){
                continue;
            }
            double i_time = abs(location[i] - x)/speed[i];
            if(i_time > MaxTime){
                LeftMax = false;
                RightMax = false;
                if(location[i] > x){
                    RightMax = true;
                }else{
                    LeftMax = true;
                }
                MaxTime = i_time;
            }else if(i_time == MaxTime){
                if(location[i] > x){
                    RightMax = true;
                }else{
                    LeftMax = true;
                }
            }
        }
        return MaxTime;
    };



    while(high - low > MAX_ERROR){ // Binary search for position
        mid = (low + high)/2;
        double currMinTime = get_time(mid);
        min_ans = min(min_ans, currMinTime);
        if(LeftMax && RightMax){
            break;
        }else if(LeftMax){
            high = mid;
        }else{
            low = mid;
        }
    }
    cout << min_ans << endl;
    return 0;
}