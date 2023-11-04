#include <bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream cin("moocast.in");
    int n; cin >> n;
    vector<pair<int,int>> coordinates(n);
    for(int i = 0; i < n;i++){
        cin >> coordinates[i].first >> coordinates[i].second;
    }
    auto distance = [&](int x1, int y1, int x2,int y2){
        int dx = abs(x2-x1);
        int dy = abs(y2-y1);
        return dx*dx + dy*dy;
    };
    auto works = [&](ll price){
        vector<bool> reached(n,false);
        vector<int> stack{0};
        reached[0] = true;
        while(!stack.empty()){
            int currentElement = stack.back();
            stack.pop_back();
            for(int i = 0; i < n;i++){
                if(!reached[i] && distance(coordinates[currentElement].first, coordinates[currentElement].second, coordinates[i].first, coordinates[i].second) <= price){
                    stack.push_back(i);
                    reached[i] = true;
                }
            }
        }
        for(int i = 0; i < n;i++){
            if(!reached[i]){
                return false;
            }
        }
        return true;
    };
    ll high = 1e6, low = 0, mid;
    ll ans = -1;
    while(low <= high){
        mid = low + (high - low)/2;
        if(works(mid)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout << ans << endl;
    return 0;
}