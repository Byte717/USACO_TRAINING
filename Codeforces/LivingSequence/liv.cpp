#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;
/*
we are basically dealing with base 9, since the 4 is being ignored.
but base 9 is 0,1,2,3,4,5,6,7,8. We want 0,1,2,3,5,6,7,8,9. So for every digit such that its greater than 3, we add 1 to that digit.

What I learned:
    - When dealing with number theory, break it into digits and look at them individually
    - base conversion is basically modding the number and dividing repeatedly.

*/

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int t; cin >> t;
    while(t--){

        ll k; cin >> k;
        vector<int> digits;

        while(k > 0){ // convert to base 9.
            digits.push_back(k%9);
            k/=9;
        }
        reverse(all(digits));

        for(int i = 0; i < digits.size();i++){
            cout << (char)(digits[i] < 4 ? (digits[i] + '0') : (digits[i] + '1'));
        }
        cout << endl;
    }
    return 0;
}