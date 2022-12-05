#include <bits/stdc++.h>

using namespace std; 

bool isOverlapping(vector<pair<int,int>> a){
    sort(a.begin(), a.end());
    for(int i=0; i<a.size(); i++){
        if(a[i].second > a[i+1].first && a[i].second < a[i+1].second)return true;
    }
    return false;
}


int main(int argc, char *argv[]) {
  vector<pair<int,int>> input = {{1, 3}, {5, 7}, {8, 12}};
  cout << isOverlapping(input);
  return 0;
}