#include <bits/stdc++.h>

using namespace std; 

int main(){
    ifstream input("balancing.in");
    long long int N, B;
    input >> N >> B;
    vector<pair<long long, long long>> cows(N);
    for(int i = 0; i < N;i++){
        input >> cows[i].first >> cows[i].second;
    }
    map<long long, long long> x;
    map<long long, long long> y;
    for(int i = 0; i < N; i++){
        if(x.count(cows[i].first) == 0){
            x.insert(make_pair(cows[i].first, 1));
        }
        if(y.count(cows[i].second) == 0){
            y.insert(make_pair(cows[i].second, 1));
        }
    }
    long long int a, b;
    vector<long long> X, Y;
    for(auto &i : x){
        X.push_back(i.first);
    }
    for(auto const& i : y){
        Y.push_back(i.first);
    }

    if(X.size() % 2 == 0){
        a = (X[(X.size()/2)] + X[X.size()/2 - 1])/2;
    }else{
        a = X[X.size()/2] + 1;
    }
    if(Y.size() % 2 == 0){
        b = (Y[(Y.size()/2)] + Y[Y.size()/2 - 1])/2;
    }else{
        b = Y[Y.size()/2] + 1;
    }
    int MaxNum = INT16_MIN, currnum = 0;
    for(int i = 0; i < N; i++){
        if(cows[i].first < a && cows[i].second > b){
            currnum++;
        }
    }
    MaxNum = max(MaxNum, currnum);
    currnum = 0; 
    for(int i = 0; i < N; i++){
        if(cows[i].first > a && cows[i].second > b){
            currnum++;
        }
    }
    MaxNum = max(MaxNum, currnum);
    currnum = 0;
    for(int i = 0; i < N; i++){
        if(cows[i].first < a && cows[i].second < b){
            currnum++;
        }
    }
    MaxNum = max(MaxNum, currnum);
    currnum = 0;
    for(int i = 0; i < N; i++){
        if(cows[i].first > a && cows[i].second < b){
            currnum++;
        }
    }
    currnum = 0;
    MaxNum = max(MaxNum, currnum);
    cout << MaxNum << endl;
    return 0; 
}