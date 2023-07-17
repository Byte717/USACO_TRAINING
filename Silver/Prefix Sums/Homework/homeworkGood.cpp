#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("homework.in","r",stdin);
    int n; cin >> n;
    vector<int> questions(n+1);
    for(int i = 0; i < n;i++){
        cin >> questions[i];
    }
    vector<int> pref(n+1,0), minimum(n+1,INT32_MAX);
    for(int i = n-1;i >= 0;i--){
        pref[i] = pref[i+1] + questions[i];
        minimum[i] = min(minimum[i-1], questions[i]);
    }
    map<int,vector<int>> ans;
    int MX = -1;
    int currElements = n - (n-2);
    for(int k = n-2;k >= 1;k--){
        int currAvg = (pref[k] - minimum[k])/currElements;
        MX = max(MX,currAvg);
        ans[currAvg].push_back(k+1);
    }
    for(int i = 0; i < ans[MX].size();i++){
        cout << ans[MX][i] << endl;
    }
    return 0;
}