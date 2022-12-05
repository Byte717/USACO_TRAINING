#include <bits/stdc++.h>

using namespace std; 

int main(){
    ifstream input("lifeguards.in");
    int numCows; input >> numCows;
    int ranges[1000]{};
    vector<pair<int,int>> shifts(numCows);
    for(int i = 0; i < numCows;i++){
        input >> shifts[i].first >> shifts[i].second;
        for(int j = shifts[i].first; j < shifts[i].second;j++){
            ranges[j] = 1;
        }
    }
    int time = 0;
    vector<int> times;
    for(int i = 0; i < numCows;i++){
        for(int j = shifts[i].first; j < shifts[i].second-1; j++){
            ranges[j] = 0;
        }
        for(int k = 1; k <= 1000;k++){
            if(ranges[k] == 1) time++;
        }
        times.push_back(time);
        time=0;
        for(int j = shifts[i].first; j <= shifts[i].second; j++){
            ranges[j] = 1;
        }
    }
    int max1 = 0;
    for(int i = 0; i < numCows;i++){
        max1 = max(max1, times[i]);
    }
    cout << max1 << endl;
    return 0; 
}