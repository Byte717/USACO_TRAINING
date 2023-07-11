#include <bits/stdc++.h>

using namespace std; 


pair<float, float> getAverage(vector<pair<int,int>> arr){
    float avgX = 0, avgY = 0;
    for(int i = 0; i < arr.size();i++){
        avgX+=arr[i].first;
        avgY+=arr[i].second;
    }
    avgX/=arr.size();
    avgY/=arr.size();
    return make_pair(avgX,avgY);
}

pair<int,int> farthestPoint(pair<float,float> avgPt, vector<pair<int,int>> arr){
    double maxDist = -1; 
    pair<int,int> farthest; 
    for(int i = 0; i < arr.size();i++){
        double dist = ((avgPt.first - arr[i].first)*(avgPt.first - arr[i].first)) + ((avgPt.second - arr[i].second)*(avgPt.second - arr[i].second));
        if(dist > maxDist){
            maxDist = dist; 
            farthest = arr[i];
        }
    }
    return farthest;
}

int area(vector<pair<int,int>> arr){
    int minX = INT16_MAX, minY = INT16_MAX, maxX = -1, maxY = -1;
    for(int i = 0; i < arr.size();i++){
        minX = min(minX, arr[i].first); 
        minY = min(minY, arr[i].second);
        maxX = max(maxX, arr[i].first);
        maxY = max(maxY,arr[i].second);
    }
    return (maxX - minX)*(maxY - minY);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("reduce.in","r",stdin);
    int n; cin >> n; 
    vector<pair<int,int>> coordinates(n);
    for(int i = 0; i < n;i++) cin >> coordinates[i].first >> coordinates[i].second;
    for(int i = 0; i < 3;i++){
        pair<float,float> average = getAverage(coordinates);
        vector<pair<int,int>>::iterator pos = find(coordinates.begin(),coordinates.end(),farthestPoint(average,coordinates));
        coordinates.erase(pos);
    }
    cout << area(coordinates) << endl;
    return 0;
}