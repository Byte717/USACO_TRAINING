#include <bits/stdc++.h>

using namespace std; 

int main(){
    ifstream input("wormhole.in");
    int n; input >> n;
    vector<pair<int,int> > portals(n); 
    for(int i = 0; i < n; i++){
        input >> portals[i].first >> portals[i].second;
    }
    int count = 0;
    for(int i = 0; i < n-1; i++) for(int j = i+1; j < n; j++){
        if(portals[i].first <= portals[j].first && portals[i].second == portals[j].second) count++;
        else if(portals[i].first >= portals[j].first && portals[i].second == portals[j].second) count ++;
    }
    cout << count << endl;
    return 0;
}