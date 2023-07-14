#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n, x; cin >> n >> x;
    int arr[n];
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    int ans = 0;
    int left = 0, right = 2, sum = 0;
    for(int i = 0; i <= 2;i++){
        sum += arr[i];
    }
    if(sum == x){
        ans++;
    }
    while(left < n && right < n){
        
    }
    return 0;
}