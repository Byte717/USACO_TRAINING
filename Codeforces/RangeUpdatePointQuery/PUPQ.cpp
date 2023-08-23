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
/*
solution: keep a running set of indeices that can be added. if its a single digit, we don;t consider it. so we keep lower bounding on the active set, looking for indices that are active between l and r

What I learned Range update Point query:
    - binary search on sets using lower and upper bound
    - using sets to store active things that need to be editied.
        - like from l to r, only certain things need to be edited. 

*/


int digitSum(int n){
    int sum = 0;
    while(n > 0){
        sum += n%10;
        n/=10;
    }
    return sum;
}

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    set<int> active;
    for(int i = 0; i < n;i++){
        cin >> a[i];
        if(a[i] > 9) active.insert(i);
    }
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l,r; cin >> l >> r; l--; r--;
            int last = l;
            while(!active.empty()){
                auto it = active.lower_bound(last);
                if(it == active.end() || *it > r) break;
                a[*it] = digitSum(a[*it]);
                int x = *it;
                active.erase(it);
                if(a[x] > 9) active.insert(x);
                last = x + 1;
            }
        }else{
            int x; cin >> x;
            cout << a[--x] << endl;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("update.in","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}