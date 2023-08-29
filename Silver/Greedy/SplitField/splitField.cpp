#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>

#define all(x) begin(x),end(x)

typedef long long ll;

using namespace std;

const ll INF = 1e18;

/*
 * Solution: since the 2 rectangles cannot intersect, there has to be a vertical line or horizontal line separating them.
 * so lets try valdating each horizontal and vertical division. Important note, to find the minArea of a set of points, its the (max X - min X) * (max Y * min Y);
 * so to do this, lets sort the points first by x and then by Y. now the order will have, if we pick the boundary between i and i + 1, i'th cow will have the max X. But it isnt 
 * necessary that it has the max Y or the Min Y so to do this we keep a prefix minimum and maximum for all the Y coordinates. So that will be enough to calculate the first rectangl
 * e that ends at i. then we need a suffix using the same approach to calculate for i + 1 to n points. then just take the min of those and using 1 square. 
 *
 * after calculating the vertical line, calculate 4 the horizontal by swaping all x and y values and repeating the above:
 *
 * What I learned Spliting the Field:
 *  - minimum Prefix and suffix sums
 *  - sorting coordinates
 *  - min enclosing area
 *
 */






int n; 
vector<pair<int,int>> cows;
ll ans = 0;

ll search(){
    sort(all(cows));
    vector<pair<int,int>> pref(n), suf(n); // keep a prefix of min Y and max Y and suffix also

    auto upd = [&](pair<int,int> a, int b) -> pair<int,int>{
        return {min(a.first,b), max(a.second,b)};
    };
    pref[0] = {cows[0].first, cows[0].second};

    for(int i = 1; i < n;i++){
        pref[i] = upd(pref[i-1], pref[i].second);
    }

    suf[n-1] = {cows[n-1].first, cows[n-1].second};
    for(int i = n-2; i >= 0; i--){
        suf[i] = upd(suf[i+1], cows[i].second);
    }
                        // Max X             -  Min X              Max Y               -  min Y) 
    ll originalArea = (ll)(cows.back().first - cows.front().first)*(pref.back().second - pref.back().first);
    ll best = INF;
    for(int i = 0; i < n+1;i++){
        if(cows[i].first != cows[i+1].first){
            //                  (max X - min X)                ( max Y,  min Y)
            ll firstRect = (ll)(cows[i].first - cows[0].first)*(pref[i].second - pref[i].first);
            ll secondRect = (ll)(cows.back().first - cows[i+1].first)*(suf[i+1].second - suf[i+1].first);
            best = min(best,firstRect+secondRect);
        }
    }
    return originalArea - best;
}

int main(){
    cin >> n;
    cows = vector<pair<int,int>>(n);
    for(auto &[x,y] : cows){
        cin >> x >> y;
    }
    ans = max(ans, search());
    for(auto &[x,y] : cows) swap(x,y);
    ans = max(ans,search());
    cout << ans << endl;
    return 0;
} 
