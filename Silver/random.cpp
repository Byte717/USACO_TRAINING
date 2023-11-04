#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    freopen("s.in","r",stdin);
    ll x, y, destX, destY;
    cin >> x >> y >> destX >> destY;
    ll n; cin >> n;
    vector<char> forecast(n);
    for(auto&i : forecast) cin >> i;
    if(x == destX && y == destY){
        cout << 0 << endl;
        return 0;
    }
    auto works = [&](ll days){
        ll tempX = 0, tempY = 0;
        for(auto i : forecast){
            switch (i){
                case 'U':
                    tempY++;
                    break;
                case 'D':
                    tempY--;
                    break;
                case 'R':
                    tempX++;
                    break;
                default:
                    tempX--;
                    break;
            }
        }
        tempX *= days/n;
        tempY *= days/n;
        ll remainder = days % n;
        for(int i = 0; i < remainder;i++){
            switch (forecast[i]){
                case 'U':
                    tempY++;
                    break;
                case 'D':
                    tempY--;
                    break;
                case 'R':
                    tempX++;
                    break;
                default:
                    tempX--;
                    break;
            }

        }

    };


    cout << works(5) << endl;
    ll low = 0, hi = 1e9, ans = -1, mid;
    while(low < hi){
        mid = low + (hi-low)/2;
        if(works(mid)){
            hi = mid - 1;
            ans = mid;
        }else{
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}