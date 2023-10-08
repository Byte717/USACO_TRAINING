#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

class part{
    public: 
        ll x, y;
        int idx;
};
part bottomMost, topMost, leftMost, rightMost;

bool interact(part &p1, part &p2){
    return (p1.x >= p2.x && p1.y >= p2.y) || (p2.x >= p1.x && p2.y >= p2.y); 
}

bool inRange(part &x){
    return (interact(x,leftMost)) || (interact(x,topMost)) || (interact(x,bottomMost));
}

bool cmp(const part &p1, const part &p2){
    if(p1.x == p2.x) return p1.y < p2.y;
    return p1.x < p2.x;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("moop.in","r",stdin);
    // freopen("moop.out","w",stdout);
    int n; cin >> n;
    vector<part> particles;
    for(int i = 0; i < n;i++){
        ll x, y; cin >> x >> y;
        particles.push_back({x,y,i});
    }

    sort(all(particles),cmp);

    queue<part> active;
    int ans = 0;

    for(int i = 0; i < n;i++){
        // first see if active is empty
        if(active.size() == 0){
            active.push(particles[i]);
            bottomMost = topMost = leftMost = rightMost = particles[i];
        }else{
            // check if this point is in range
            if(inRange(particles[i])){
                active.push(particles[i]);
                if(particles[i].y > topMost.y){
                    topMost = particles[i];
                }
                if(bottomMost.y > particles[i].y){
                    bottomMost = particles[i];
                }

                if(leftMost.x > particles[i].x){
                    leftMost = particles[i];
                }

                if(rightMost.x < particles[i].x){
                    rightMost = particles[i];
                }
            }else{
                ans++;
                active = queue<part>{};
                active.push(particles[i]);
                bottomMost = topMost = leftMost = rightMost = particles[i];
            }
        }
    }

    if(!active.empty()){
        ans++;
    }
    cout << ans << endl;
    return 0;
}