#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("tracing.in","r",stdin);
    int N,T; cin >> N >> T;
    vector<int> cows(N);
    for(int i = 0; i < N;i++) cin >> cows[i];
    vector<pair<int,pair<int,int> > > handshakes;
    for(int i = 0; i < T;i++){
        int t,x,y; cin >> t >> x >> y;
        handshakes.push_back(make_pair(t,make_pair(x,y)));
    }
    sort(handshakes.begin(),handshakes.end());
    int minK = T;
    int maxK = 0;
    for(int i = 0; i < n;i++){
        for(int k = 0; k < T+1;k++){

        }
    }

    return 0;
}