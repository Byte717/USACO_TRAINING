#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 
// find minimum in a range
const int MAXN = 100'001;
const int LOG = 17;
int a[MAXN];
int table[MAXN][LOG];

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){
        ret++;
    }
    return ret;
}

int query(int left, int right){
    int len = right - left + 1;
    int k = LOG2(len);
    return min(table[left][k],table[right-(1<<k)+1][k]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;
    for(int i = 0; i < n;i++){
        cin >> a[i];
        table[i][0] = a[i];
    }
    for(int j = 1; j < LOG;j++){
        for(int i = 0; i + (1 << j)-1 < n;i++){ // if i + size of range(2 ^ j) < n 
            table[i][j] = min(table[i][j-1], table[i + (1 << j-1)][j-1]);
        }
    }
    return 0;
}