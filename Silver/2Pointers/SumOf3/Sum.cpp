#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n,x; cin >> n >> x;
    vector<pair<int,int>> arr(n);
    for(int i = 0; i < n;i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr,arr+n);
    for(int i = 1; i < n-1;i++){
        int left = 0, right = n-1;
        while(left != right){
            if(arr[left].first + arr[i].first + arr[right].first > x){
                right--;
            }else if(arr[left].first + arr[i].first + arr[right].first < x){
                left++;
            }else if(arr[left].first + arr[i].first + arr[right].first == x && left != i && right != i){
                cout << arr[left].second << " " << arr[i]
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}