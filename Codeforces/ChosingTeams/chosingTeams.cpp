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
so we count the number of students that can participate in the next k years, then its that number/3

WHat I learned: 
    - just keep a count of what works individually and calculate from there in greedy
    - like the answer would be individual/3
*/

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int n, k; cin >> n >> k;
    int ans = 0;
    for(int i = 0; i < n;i++){
        int x; cin >> x;
        if(5 - x >= k){
            ans++;
        }
    }
    cout << ans/3 << endl;
    return 0;
}