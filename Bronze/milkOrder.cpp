#include <bits/stdc++.h>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("milkorder.in","r",stdin);
    int n, m, k; cin >> n >> m >> k; 
    vector<int> socialH(m);
    map<int,int> social;
    for(int i = 0; i < m; i++){
        cin >> socialH[i];
        social.insert(make_pair(socialH[i],i));
    }
    vector<int> order(n,-1);
    for(int i = 0; i < k;i++){
        int c, p; cin >> c >> p;
        if(c == 1) cout << p;
        order[p-1] = c;
        if(social.count(c) != 0){
            for(int j = (p-1) - social[c]; j < ((p-1) - social[c]) + m;j++){
                order[j] = socialH[abs(j-social[c])];
                if(socialH[abs(j-social[c])] == 1){
                    cout << abs(j-social[c]) + 1 << endl; 
                    return 0;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < n;i++){
        if(order[i] == -1){
            cout << i+1 << endl;
            break;
        }
    }

    return 0;
}