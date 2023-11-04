#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std; 

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

struct Cow{
    int idx;
    ll x, y;
};
bool cmp(Cow &c1, Cow &c2){ // sort by x, then by y
    if(c1.x == c2.x){return c1.y < c2.y;}
    return c1.x < c2.x;
}

bool cmp2(Cow &c1, Cow &c2){ // sort by y, then by x
    if(c1.y == c2.y){return c1.x < c2.x;}
    return c1.y < c2.y;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;
    vector<Cow> cowsN,cowsE;
    for(int i = 0; i < n;i++){
        char dir;ll x, y; cin >> dir >> x >> y;
        if(dir == 'N'){
            cowsN.push_back({i,x,y});
        }else{
            cowsE.push_back({i,x,y});
        }
    }
    sort(all(cowsN), cmp);
    sort(all(cowsE),cmp2);
    vector<bool> stopped(n,false);
    vector<int> blame(n,0);

    for(auto &CowEast : cowsE){
        for(auto &CowNorth : cowsN){
            if(!stopped[CowEast.idx] && !stopped[CowNorth.idx] && CowEast.y >= CowNorth.y && CowEast.x <= CowNorth.y){
                int xlen = CowNorth.x - CowEast.x;
                int ylen = CowEast.y - CowNorth.y;

                if(ylen > xlen){ // east Cow Stopped and then blame will be added to North Cow
                    stopped[CowEast.idx] = true;
                    blame[CowNorth.idx] += 1 + blame[CowEast.idx];
                }else if(xlen > ylen){ // North cow is stopped and blame added to east cow
                    stopped[CowNorth.idx] = true;
                    blame[CowEast.idx] += 1 + blame[CowNorth.idx];
                }
            }
        }
    }
    for(int i : blame){cout << i << endl;}
    return 0;
}
