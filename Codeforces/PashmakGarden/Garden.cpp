#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

struct Point
{
    int x, y;
};


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    Point p1,p2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    if(p1.x == p2.x){
        int dist = abs(p1.y - p2.y);
        Point p3,p4;
        p3.x = p1.x + dist;
        p4.x = p2.x + dist;
        p3.y = p1.y;
        p4.y = p2.y;
        cout << p3.x << ' ' << p3.y << ' ';
        cout << p4.x << ' ' << p4.y << endl;
    }else if(p1.y == p2.y){
        int dist = abs(p1.x - p2.x);
        Point p3,p4;
        p3.y = p1.y + dist;
        p4.y = p2.y + dist;
        p3.x = p1.x;
        p4.x = p2.x;
        cout << p3.x << ' ' << p3.y << ' ';
        cout << p4.x << ' ' << p4.y << endl;
    }else{
        int distX = abs(p1.x - p2.x);
        int distY = abs(p1.y - p2.y);
        if(distX != distY){
            cout << -1 << endl;
            return 0;
        }
        Point p3;
        p3.x = p1.x;
        p3.y = p2.y;
        Point p4;
        p4.x = p2.x;
        p4.y = p1.y;
        cout << p3.x << ' ' << p3.y << ' ';
        cout << p4.x << ' ' << p4.y << endl;
    }
    return 0;
}