#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};
/*
initial thoughts, all points can be connected in a graph if they are on the same vertical or horizontal plane
these can be found using the sweep line algorithm twice. But to make those edges, it becomes O(n^2) really fast.

solution: sweepline wasnt needed. Instead, store those vertical and horizontal edges for a certian x or y 
in a map that contains the coordinate and all of indexes of mirrors on it. then its a bfs that we look at considering the direction.

*/


// struct Point{
//     ll x, y;
//     int idx;
// };
// bool cmpX(Point &p1, Point &p2){
//     return p1.x < p2.x;
// }
// bool cmpY(Point &p1, Point &p2){
//     return p1.y < p2.y;
// }
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("lasers.in","r",stdin);
    int n; cin >> n;
    vector<pair<int,int>> points(n+2);

    unordered_map<int,vector<int>> lines[2];
    for(int i = 0; i < n+2;i++){
        cin >> points[i].first >> points[i].second;
        lines[0][points[i].first].push_back(i);
        lines[1][points[i].second].push_back(i);
    }

    queue<pair<int,bool>> q;
    q.push({0,true});q.push({0,false});
    vector<int> dist(n+2,1e9);
    dist[0] = 0;

    while(!q.empty()){
        int curr= q.front().first;
        bool beamdir = q.front().second;
        q.pop();
        int dir = (beamdir ? 0 : 1);
        int coordinate = (beamdir ? points[curr].first : points[curr].second);
        for(int point : lines[dir][curr]){
            if(dist[point] == 1e9){
                q.push({point,!beamdir});
                dist[point] = dist[curr] + 1;
            }
        }
    }
    if(dist[1] == 1e9){
        cout << -1 << endl;
    }else{
        cout << dist[1] - 1 << endl;
    }
    // int n; cin >> n;
    // Point laser, barn; 
    // cin >> laser.x >> laser.y >> barn.x >> barn.y;
    // laser.idx = 0; barn.idx = n+1;
    // vector<Point> mirrors(n);
    // int i = 1;
    // for(auto &[x,y,idx] : mirrors){
    //     cin >> x >> y;
    //     idx = i;
    //     i++;
    // }
    // mirrors.push_back(laser);
    // mirrors.push_back(barn);
    // vector<vector<int>> adj(n+2)
    // sort(all(mirrors),cmpX);
    // queue<Point> active;
    // for(int i = 0; i < n;i++){
    //     if(active.empty()){
    //         active.push(mirrors[i]);
    //     }else{
    //         if(active.front().x == mirrors[i].x){
    //             active.push(mirrors[i]);
    //         }else{
    //             while(!q.empty)
    //         } 
    //     }
    // }
    return 0;
}