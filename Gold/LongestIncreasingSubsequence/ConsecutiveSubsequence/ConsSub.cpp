#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("ConsSub.in","r",stdin);
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    vector<int> lis;
    for(int &i: arr){
        int pos = lower_bound(lis.begin(),lis.end(),i) - lis.begin();
        if(pos == lis.size()){
            lis.push_back(i);
        }else{
            lis[pos] = i;
        }
    }
    cout << lis.size() << endl;
    for(int i = 0; i < lis.size();i++){
        cout << lis[i] << " ";
    }
    cout << endl;
    return 0;
}