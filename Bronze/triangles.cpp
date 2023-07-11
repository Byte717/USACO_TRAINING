#include <bits/stdc++.h>

using namespace std;

bool isValid(pair<int,int> c1, pair<int, int> c2, pair<int,int> c3){
    bool x = false; 
    bool y = false; 
    if(c1.first == c2.first || c2.first == c3.first || c1.first == c3.first)y = true; 
    if(c1.second == c2.second || c2.second == c3.second || c1.second == c3.second) x = true;
    return x && y;
}

int calcArea(pair<int, int> c1, pair<int,int> c2, pair<int,int> c3){
    int ys; int xs; 
    if(c1.first == c2.first) ys = abs(c1.second - c2.second);
    if(c2.first == c3.first) ys = abs(c2.second - c3.second);
    if(c1.first == c3.first) ys = abs(c1.second - c3.second);
    if(c1.second == c2.second) xs = abs(c1.first - c2.first);
    if(c2.second == c3.second) xs = abs(c2.first - c3.first);
    if(c1.second == c3.second) xs = abs(c1.first - c3.first);
    return xs*ys;
}

int main(){
    freopen("triangles.txt","r", stdin);
    int n; cin >> n; 
    vector<pair<int,int>> coordinates(n);
    for(auto& x : coordinates){
        cin >> x.first >> x.second;
    }
    int maxArea = INT16_MIN;
    for(int i = 0; i < n;i++) for(int j = i+1;j < n;j++) for(int k = j+1; k < n;k++){
        if(isValid(coordinates[i],coordinates[j],coordinates[k])){
            maxArea = max(maxArea,calcArea(coordinates[i],coordinates[j],coordinates[k]));
        }
    }
    cout << maxArea << endl;

    return 0; 
}