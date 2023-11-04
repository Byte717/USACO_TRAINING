#include <bits/stdc++.h>

using namespace std;


int findMax(int arr[]){
    int max = INT_MIN;
    for(int i = 0; i < 3;i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;

}


int main(){
    int cows[3] = {};
    ifstream input("measurement.in");
    int changes = 0;
    int lastMax = INT_MIN;
    int N;
    int day;
    string name, amount;
    input >> N;
    map<int, pair<string,string>> log;
    for(int i = 0; i < N;i++){
        input >> day >> name >> amount;
        log.insert(pair<int,pair<string,string>>(day, make_pair(name, amount)));
    }
    for(auto const& x : log){
        if(x.second.first == "Bessie"){
            cows[0] += stoi(x.second.second);
            lastMax = findMax(cows);
            if(cows[0] > lastMax || cows[0] == lastMax){
                lastMax = findMax(cows);
                changes++;
            }
        }
        if(x.second.first == "Elsie"){
            cows[1] += stoi(x.second.second);
            lastMax = findMax(cows);
            if(cows[1] > lastMax || cows[1] == lastMax){
                lastMax = findMax(cows);
                changes++;
            }
        }
        if(x.second.first == "Mildred"){
            cows[2] += stoi(x.second.second);
            lastMax = findMax(cows);
            if(cows[2] > lastMax || cows[2] == lastMax){
                lastMax = findMax(cows);
                changes++;
            }
        }
    }
    cout << changes << endl;

    return 0;
}