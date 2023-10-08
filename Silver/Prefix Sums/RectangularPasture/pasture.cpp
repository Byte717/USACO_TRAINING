#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <map>
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
int main(){
    int n; cin >> n;

    vector<pair<int,int>> cows(n);
    for(int i = 0; i < n;i++){
        cin >> cows[i].first >> cows[i].second;
    }
    
    sort(all(cows));
    map<int,int> xCompress;
    for(int i = 0; i < n;i++){
        xCompress[cows[i].first] = i;
    }

    sort(all(cows),[&](pair<int,int> &a,pair<int,int> &b){
        return a.second < b.second;
    });
    
    map<int,int> yCompress;
    for(int i = 0; i < n;i++){
        yCompress[cows[i].second] = i;
    }

    for(auto &[x,y] : cows){
        x = xCompress[x];
        y = yCompress[y];
    }
    sort(all(cows));

    vector<vector<int>> prefLess(n,vector<int>(n+1));
    vector<vector<int>> prefGreater(n,vector<int>(n+1));
    for(int i = 0; i < n;i++){
        int currY = cows[i].second
        for(int j = 1;j <=n;j++){
            prefLess[currY][j] = (prefLess[currY][j-1] + (cows[j-1].second < currY));
            prefGreater[currY][j] = (prefGreater[currY][j-1] + (cows[j-1].second > currY));
        }
    }

    ll total = 0;
    for(int i = 0; i < n;i++){
        for(int j = i+1;j < n;j++){
            int bottom = min(cows[i].second, cows[j].second);
            int top = max(cows[i].second, cows[j].second);

            int bottomTotal = 1 + prefLess[bottom][j+1] - prefLess[bottom][i];
            int topTotal = 1 + prefGreater[top][j+1] - prefGreater[top][i];
            total += (ll)(bottomTotal*topTotal);
        }
    }
    total += n + 1;
    cout << total << endl;
    return 0;
}
