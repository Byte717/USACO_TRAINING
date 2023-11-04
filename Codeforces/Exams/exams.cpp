#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("exams.in","r",stdin);
    int n; cin >> n;
    vector<pair<ll,ll>> exams(n);
    for(int i = 0; i < n;i++){
        cin >> exams[i].first >> exams[i].second;
    }
    sort(all(exams));
    ll currDay = 0;
    for(auto &[x,y] : exams){
        if(y >= currDay){
            currDay = y;
        }else{
            currDay = x;
        }
    }
    cout << currDay << endl;
    return 0;
}