#include <bits/stdc++.h>
#define INF 1e9
#define mod 1e9+7

typedef long long ll;

using namespace std; 


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("RU.in","r",stdin);
    int n, q; cin >> n >> q;
    vector<ll> arr(n);
    for(int i = 0; i < n;i++){
        cin >> arr[i];

    }
    for(int i = 0; i < q;i++){
        int type; cin >> type;
		if(type == 1){

		}else{
			int k; cin >> k;
			cout << arr[--k] << endl;
		}
    }
    return 0;
}