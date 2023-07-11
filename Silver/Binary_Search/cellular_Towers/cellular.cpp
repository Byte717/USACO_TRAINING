#include <bits/stdc++.h>
#define ll long long


using namespace std; 


int BinarySearchLower(vector<int> array, int target){
    int low = 0, high = array.size() - 1, mid;
    int ans = INT32_MIN;
    while(low <= high){
        mid = ceil((low+high)/2);
        if(array[mid] < target){
            low = mid+1;
            ans = array[mid];
        }else{
            high = mid - 1;
        }
    }
    return ans;
}


bool exists(vector<int> array, int target){
    int low = 0, high = array.size() - 1, mid;
    while(low <= high){
        mid = ceil((low+high)/2);
        if(array[mid] == target){
            return true;
        }
        if(array[mid] > target){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return false;
}

int main(){
    freopen("cellular.in","r",stdin);
    int m, n;
    vector<int> cities,towers;
    cin >> n >> m;
    cities = vector<int>(n,0);
    towers = vector<int>(m,0);
    for(int i = 0; i < n;i++) cin >> cities[i];
    for(int i = 0; i < m;i++) cin >> towers[i];
    sort(cities.begin(),cities.end());
    sort(towers.begin(),towers.end());
    int minRadius = 0;
    for(int i = 0; i < n;i++){
       if(exists(towers,cities[i]))continue;
        auto nextElement = (lower_bound(towers.begin(),towers.end(),cities[i])); 
        auto previousElement = BinarySearchLower(towers,cities[i]);
        if(nextElement == towers.end()){
            if(cities[i]-minRadius <= previousElement) continue;
            minRadius = abs(cities[i]-previousElement);
        }else if(previousElement == towers.end()){
            if(cities[i]+minRadius >= nextElement) continue;
            minRadius = abs(cities[i]-nextElement);
        }else{
            if(cities[i]+minRadius >= *nextElement || cities[i]-minRadius <= *previousElement) continue;
            minRadius = min(abs(cities[i]-*nextElement),abs(cities[i]-*previousElement));
        }
    }
    cout << minRadius << endl;


    return 0;
}