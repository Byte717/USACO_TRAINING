#include <bits/stdc++.h>

using namespace std; 
int K, N;

int fastest_time(int distance, int max_speed){
    int speed_up_dist = 0, slow_down_dist = 0, time = 0;

    for(int currSpeed = 1; ;currSpeed++){
        speed_up_dist+=currSpeed;
        time++;
        if(speed_up_dist+slow_down_dist >= distance){
            return time;
        }

        if(currSpeed >= max_speed){
            time++;
            slow_down_dist+=currSpeed;
            if(speed_up_dist+slow_down_dist >= distance){
                return time;
            }
        }
    }
}



int main(){
    freopen("race.in","r",stdin);
    cin >> K >> N;
    int x;
    for(int i = 0; i < N;i++){
        cin >> x;
        cout << fastest_time(K,x) << endl;
    } 
}