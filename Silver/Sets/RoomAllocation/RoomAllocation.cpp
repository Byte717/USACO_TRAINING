#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

bool cmp(const pair<pair<int, int>,int> &p1, const pair<pair<int, int>,int> &p2){
    return p1.first.first < p2.first.first;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;
    vector<pair<pair<int,int>,int>> v(n);
    for(int i = 0; i < n;i++){
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    vector<int> ans(n);
    int rooms = 0, lastRoom = 0;
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < n; i++){
        if(pq.empty()){
            lastRoom++;
            pq.push_back({-v[i].first.second,lastRoom});
            ans[v[i].second] = lastRoom;
        }else{
            auto minimum = pq.front();
            if(mimimum.first < v[i].first.first){
                pq.pop();
                pq.push(make_pair(-v[i].first.second,minimum.second));
                ans[v[i].second] = minimum.second;
            }else{
                lastRoom++;
                pq.push(make_pair(-v[i].first.second, lastRoom));
                ans[v[i].second] = lastRoom;
            }
        }
        rooms = max(rooms, pq.size());
    }
    cout << rooms << endl;
    for(int i = 0; i < n;i++){cout << ans[i] << endl;}
    return 0;
}