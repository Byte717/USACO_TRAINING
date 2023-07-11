#include <bits/stdc++.h>

using namespace std; 


string colors;
int n;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("whereami.in","r",stdin);
    cin >> n;
    cin >> colors;
    int minK = n;
    map<int, vector<string>> allSubsets;
    for(int i = 0; i < n;i++) for(int j = i; j < n;j++){
        string temp;
        for(int k = i; k <= j;k++)temp+=colors[k];
        if(allSubsets.count(temp.size()) != 0){
            allSubsets[temp.size()].push_back(temp);
        }else{
            vector<string> tempVec = {temp};
            allSubsets.insert(make_pair(temp.size(),tempVec));
        }
    }
    for(auto& x : allSubsets){
        bool good = true;
        for(int i = 0; i < x.second.size();i++) for(int j = i+1; j < x.second.size();j++){
            if(x.second[i] == x.second[j]){
                good = false;
            }
        }
        if(good){
            minK = x.first;
            break;
        }
    }
    cout << minK << endl;
    return 0;
}