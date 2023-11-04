#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){
        ret++;
    }
    return ret;
}

struct customer{
    int time; int operate;
};
bool cmp(customer &c1, customer &c2){
    return c1.time < c2.time;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("res.in","r",stdin);
    int n; cin >> n;
    vector<customer> c;
    for(int i = 0; i < n;i++){
        int a, b; cin >> a >> b;
        c.push_back({a,1});
        c.push_back({b,-1});
    }
    sort(all(c),cmp);
    int currCustomers = 0, MX = 0;
    for(auto & i : c){
        currCustomers += i.operate;
        MX = max(MX,currCustomers);
    }
    cout << MX << endl;
    return 0;
}
