#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

struct Tree{
    int ripeDay;
    int harvest;
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("fruits.in","r",stdin);
    int n, v; cin >> n >> v;
    vector<Tree> trees(n);
    for(int i = 0; i < n;i++){
        cin >> trees[i].ripeDay >> trees[i].harvest;
    }
    int ans = 0;
    int fromLastDays = 0;
    for(int day = 1; day <= 3001;day++){
        int today = 0;
        for(auto &[ripeDay, harvest] : trees){
            if(ripeDay == day){
                today += harvest;
            }
        }
        if(today + fromLastDays <= v){
            ans += fromLastDays + today;
            fromLastDays = 0;
        }else{
            ans += v;
            int tv = v - fromLastDays;
            if(tv < 0) tv = 0;
            fromLastDays = today - tv;
        }
    }
    cout << ans << endl;
    // sort(all(trees),[](const Tree&t1, const Tree&t2){return t1.ripeDay < t2.ripeDay;});
    // int totalCollected = 0;
    // int collectedToday = 0;
    // int day = 0;
    // int leftToday = v;
    // for(auto &[ripeDay, harvest] : trees){
    //     if(day == ripeDay){
    //         if(leftToday != 0){
    //             collectedToday += min(harvest, leftToday);
    //             leftToday -= min(harvest, leftToday);
    //         }
    //     }else{
    //         totalCollected += collectedToday;
    //         collectedToday = 0;
    //         leftToday = v;
    //         day = ripeDay;
    //         collectedToday += min(harvest, leftToday);
    //         leftToday -=  min(harvest, leftToday);
    //     }
    // }
    // totalCollected += collectedToday;
    // cout << totalCollected << endl;
    return 0;
}