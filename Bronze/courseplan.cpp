#include <bits/stdc++.h>

using namespace std; 

int main(){
    freopen("courseplan.in","r",stdin);
    int n, k; cin >> n >> k;
    vector<int> difficulties(n);
    for(int i = 0; i < n; i++){
        string s;int x; cin >> s >> x; 
        difficulties[i] = x;
    }
    sort(difficulties.begin(),difficulties.end());
    int sum = 0; 
    for(int i = 0; i < k;i++){
        sum+=difficulties[i];
    }
    cout << sum << endl;

    return 0;
}