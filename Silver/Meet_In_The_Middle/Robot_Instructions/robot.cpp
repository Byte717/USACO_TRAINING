#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

typedef long long ll;

using namespace std;


struct Point{
    ll x, y;
};


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("robot.in","r", stdin);
    int n; cin >> n;
    Point target; cin >> target.x >> target.y;
    vector<Point> dirs(n);
    for(auto &[x,y] : dirs){
        cin >> x >> y;
    }
    vector<pair<Point,int>> = all_subsets();
    return 0;
}

