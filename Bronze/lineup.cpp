#include <bits/stdc++.h>

using namespace std;

vector<string> names = {"Bessie", "Buttercup", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("lineup.in","r",stdin);
    int n; cin >> n;
    vector<pair<string,string>> constraints(n);
    for(int i = 0; i < n;i++){
        string x,y, g1,g2,g3,g4;
        cin >> x >> g1 >> g2 >> g3 >> g4 >> y;
        constraints[i] = make_pair(x,y);
    }
    while(true){
        next_permutation(names.begin(),names.end());
        bool allSatisfied = true;
        for(auto& x : constraints){
            int indexOfFirst = find(names.begin(),names.end(),x.first) - names.begin();
            int indexOfSecond = find(names.begin(),names.end(),x.second) - names.begin();
            if(!(indexOfFirst == indexOfSecond - 1 || indexOfFirst == indexOfSecond + 1)){
                allSatisfied = false;
            }
        }
        if(allSatisfied)break;
    }
    for(int i = 0; i < 7; i++){
        cout << names[i] << endl;
    }
    return 0;
}