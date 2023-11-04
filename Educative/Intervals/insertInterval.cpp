#include <bits/stdc++.h>

using namespace std;


vector<pair<int, int> > merge(vector<pair<int, int> > array){
    sort(array.begin(), array.end());
    vector<pair<int, int> > result;
    int start = array[0].first;
    int end = array[0].second;
    for(int i = 1; i < array.size(); i++){
        if(end >= array[i].first  && end <= array[i].second){
            end = array[i].second;
        }else{
            result.push_back({start,end});
            start = array[i].first;
            end = array[i].second;
        }
    }
    result.push_back({start,end});
    return result;
}


vector<pair<int, int> > insert(vector<pair<int, int> > array, pair<int, int> NewInterval){
    vector<pair<int, int> > newVector;
    for(int i = 1; i < array.size(); i++){
        if(NewInterval.first)
    }
}


int main(int argc, char **argv){
    vector<pair<int, int> > arr =  {{1, 3}, {5, 7}, {8, 12}};
    pair<int, int> newInterval = {4, 6};
    arr.push_back(newInterval);
    arr = merge(arr);
    for(int i = 0; i < arr.size();i++){
        cout << "(" << arr[i].first << "," << arr[i].second << ")" << endl;
    }

    return 0;
}