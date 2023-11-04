#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream input("cowqueue.in");
    long long n; input >> n;
    vector<pair<long long, long long>> times(n);
    for(int i = 0; i < n; i++){
        input >> times[i].first >> times[i].second;
    }
    sort(times.begin(), times.end());
    long long start = times[0].first, maximum = times[0].first+times[0].second;
    for(int i = 1; i < n; i++){
        if(times[i].first >= maximum){
            maximum = times[i].first + times[i].second;
            start = times[i].first;
        }else if(times[i].first < maximum && times[i].first >= start){
            maximum = maximum + times[i].second;
            start = times[i].first;
        }
    } 
    cout << maximum << endl;
    return 0;
}