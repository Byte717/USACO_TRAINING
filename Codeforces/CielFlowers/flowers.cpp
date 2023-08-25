#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

/*

What I learned Ciel flowers:
    - try to think of multiple greedy approaches and take the optimal one
    - think of a mathematical solution (like formulas) to speed things up

*/

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("flowers.in","r",stdin);
    ll r, g , b;
    cin >> r >> g >> b;
    if(r == 0 && (b == 0 || b == 1) && (g == 0 || g == 1)){
        cout << 0 << endl;
        return 0;
    }
    ll MX = 0;
    for(int mixingBouqet = 0; mixingBouqet < 3;mixingBouqet++){
        ll ans = mixingBouqet;
        ll rP = r-mixingBouqet, gP = g - mixingBouqet, bp = b - mixingBouqet;
        ans += rP/3 + gP/3 + bp/3;
        MX = max(MX, ans); 
    }
    cout << MX << endl;
    // if(r == 3 && g == 5 && b == 5){
    //     cout << 4 << endl;
    //     return 0;
    // }
    // ll ans1 = r/3 + g/3 + b / 3;
    // ll rPrime = r % 3, gPrime = g%3, bPrime = b % 3;
    // while(rPrime > 0 && gPrime > 0 && bPrime > 0){
    //     ans1++;
    //     rPrime--;
    //     bPrime--;
    //     gPrime--;
    // }

    // ll ans2 = 0;
    // while(r > 0 && g > 0 && b > 0){
    //     ans2++;
    //     r--;
    //     g--;
    //     b--;
    // }
    // if(r > 0){
    //     ans2 += r/3;
    // }
    // if(b > 0){
    //     ans2 += b/3;
    // }
    // if(g > 0){
    //     ans2 += g/3; 
    // }
    // cout << max(ans1, ans2) << endl;
    return 0;
}