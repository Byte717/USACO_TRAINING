#include <bits/stdc++.h>
#define ll long long
#define INF 1e5

using namespace std; 

int n;
vector<int> adj;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("shuffle.in","r",stdin); freopen("shuffle.out","w",stdout);
    cin >> n;
    adj = vector<int>(n,0);
    vector<int> afterShuffle(n,0);
    for(int i = 0; i < n;i++){
        cin >> adj[i];
        adj[i]--;
        afterShuffle[a[i]]++;
    }
    int ans = n;
    queue<int> noCows;

    for(int i = 0; i < n;i++){
        if(afterShuffle[i] == 0){
            noCows.push(i);
            ans--;
        }
    }

    while(!noCows.empty()){
        int curr = noCows.front(); noCows.pop();
        if(--afterShuffle[a[curr]] == 0){
            noCows.push(a[curr]);
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}