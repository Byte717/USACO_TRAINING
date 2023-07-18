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
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n, m, r; cin >> n >> m >> r;
    vector<int> cows(n);
    for(int &i : cows){cin >> i;}
    vector<pair<int,int>> stores(m);
    for(pair<int,int> &i : stores){ cin >> i.second >> i.first;}
    vector<int> rent(r);
    for(int &i : rent){cin >> i;}
    sort(rall(cows));
    sort(rall(stores));
    sort(rall(rent));
    int cowIdx = 0, storeIdx = 0, rentIdx = 0;
    ll MxMoney = 0;
    while(cowIdx < n){
        int amount = cows[cowIdx];
        int sellMoney = 0;
        int currStore = storeIdx;
        
    }
    return 0;
}
