#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int xs[n], ys[n];
    for(int i = 0; i < n; i++){
        cin >> xs[i];
    }
    for(int i = 0; i < n; i++){
        cin >> ys[i];
    }
    vector<int> dist;
    for(int i = 0; i < n; i++){
        for(int j  = 0; j < n; j++){
            int currDist = (xs[i] - xs[j])*(xs[i] - xs[j]) + (ys[i] - ys[j])*(ys[i] - ys[j]);
            dist.push_back(currDist);
            currDist = 0;
        }
    }
    int maxdist = INT16_MIN;
    for(int i = 0; i < dist.size();i++){
        maxdist = max(maxdist, dist[i]);
    }
    cout << maxdist << endl;
    return 0;
}