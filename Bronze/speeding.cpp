#include <bits/stdc++.h>

using namespace std;


int maxOverSpeed(int N, int M, pair<int, int> limit[], pair<int, int> tractor[]){
    int idx1 = 0;
    int idx2 = 0;
    vector<int> speeds;
    while(idx1 < N && idx2 < M){
        speeds.push_back(tractor[idx2].second - limit[idx1].second);
        if(limit[idx1].first == tractor[idx2].first){
            idx1++;
            idx2++;
        }else if(limit[idx1].first > tractor[idx2].first){
            limit[idx1].first = limit[idx1].first -  tractor[idx2].first;
            idx2++;
        }else if(limit[idx1].first < tractor[idx2].first){
            tractor[idx2].first = tractor[idx2].first - limit[idx1].first;
            idx1++;
        }
    }
    int max = 0;
    for(size_t i = 0; i < speeds.size(); i++){
        if(speeds[i] > max){
            max = speeds[i];
        }
    }
    return max;
}

int main(){
    ifstream input("speeding.in");
    vector<int> speeds;
    int N, M;
    input >> N >> M;
    int miles,speed;
    pair<int, int> limits[N];
    pair<int, int> tractor[M];
    for(int i = 0; i < N; i++){
        input >> miles >> speed;
        limits[i].first = miles;
        limits[i].second = speed;
    }
    for(int i = 0; i < M; i++){
        input >> miles >> speed;
        tractor[i].first = miles;
        tractor[i].second = speed;
    }
    cout << maxOverSpeed(N, M, limits, tractor);
    
    return 0;
}