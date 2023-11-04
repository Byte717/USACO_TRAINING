#include <bits/stdc++.h>
#define ll long long


using namespace std;



int main(){
    freopen("haybales.in","r",stdin);
    int N, Q; cin >> N >> Q;
    vector<ll> locations(N);
    for(int i = 0; i < N;i++){
        cin >> locations[i];
    }
    sort(locations.begin(),locations.end());
    for(int i = 0; i < Q;i++){
        int q1, q2; cin >> q1 >> q2;
        cout << upper_bound(locations.begin(),locations.end(),q2) - lower_bound(locations.begin(),locations.end(),q1) << endl;
    }


    return 0;
}