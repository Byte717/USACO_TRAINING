#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("eggs.in","r",stdin);
    int n; cin >> n;
    vector<pair<int,int>> eggs(n);
    int A = 0, G = 0;
    for(int i = 0; i < n;i++){
        cin >> eggs[i].first >> eggs[i].second;
    }
    for(int i = 0; i < n;i++){
        int tempA = A + eggs[i].first;
        if(abs(tempA - G) > 500){
            G+= eggs[i].second;
            cout << "G";
        }else{
            A += eggs[i].first;
            cout << "A";
        }
    }
    return 0;
}