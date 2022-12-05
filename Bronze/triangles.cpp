#include <bits/stdc++.h>

using namespace std; 

int calcDist(int x1,int y1,int x2,int y2){
    if(x2 == x1){
        return max(y2,y1) - min(y2,y1);
    }
    if(y2 == y1){
        return max(x2,x1) - min(x2,x1); 
    }
    return sqrt(((y2-y1)*(y2-y1))+((x2-x1)*(x2-x1))); 
    
}
bool isParellel(int x1,int y1,int x2, int y2){
    if(x2 == x1){
        return true;
    }
    if(y2 == y1){
        return true; 
    }
    return false;
}


int main(){
    ifstream input("triangles.txt");
    int numCoordinates;
    input >> numCoordinates;
    pair<int, int> arr[100];
    vector<int> distances; 
    for(int i = 0; i < numCoordinates;i++){
        input >> arr[i].first >> arr[i].second; 
    }
    for(int i = 0; i < numCoordinates - 1; i++){
        for(int j = i+1; j < numCoordinates; j++){
            if(isParellel(arr[i].first,arr[i].second,arr[j].first,arr[j].second)){
                distances.push_back(calcDist(arr[i].first,arr[i].second,arr[j].first,arr[j].second));
            }
        }
    }
    double maxnum = 0.0;
    for(int i = 0; i < distances.size(); i++){
        for(int j = 0;j < distances.size();j++){
            maxnum = max(maxnum, 0.5*distances[i]*distances[j]);
        }
    }
    cout << maxnum << endl;
    return 0; 
}