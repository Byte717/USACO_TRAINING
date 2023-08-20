#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

/*
solution: to minimize, look for a chunk of size n with minimal spaces. to maximize, look at the first 2, and their gaps, or the last 2 and their gaps

What I learned:
    -

*/

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;
    vector<int> herd(n);
    for(int i = 0; i < n;i++){
        cin >> herd[i];
    }
    sort(all(herd));
    int minMoves = INF;
    if(herd[n-2]-herd[0] == n-2 && herd[n-1]-herd[n-2] > 0){
        minMoves = 2;
    }else if(herd[n-1] - herd[1] == n-2 && herd[1]-herd[0] > 2){
        minMoves = 2;
    }else{
        int farthestCow = 0;
        for(int currentCow = 0; currentCow < n;currentCow++){
            while(farthestCow + 1 < n && herd[farthestCow] - herd[currentCow] < n){
                farthestCow++;
            }
            minMoves = min(minMoves,n-(farthestCow-currentCow + 1)); // the number of cows in between is far - curr + 1. so the number of spaces to fill is n - that number
        }
    }
    int gapNum = 0; 
    for(int i = 1; i < n;i++){gapNum+= herd[i]-herd[i-1] + 1;}
    int maxMoves = max(gapNum-(herd[1]-herd[0]-1), gapNum -(herd[n-1]-herd[n-2]-1));
    cout << minMoves << endl << maxMoves << endl;
    return 0;
}