#include <bits/stdc++.h>

using namespace std; 


int numCommon(set<string> s1, set<string> s2){
    int Common = 0;
    for(auto const& x : s1){
        if(s2.count(x) > 0){
            Common++;
        }
    }
    return Common;
}

int main(){
    ifstream input("guess.in");
    int n; input >> n; 
    vector<set<string>> animals(n);
    for(int i = 0; i < n; i++){
        string name;
        int traitNum;
        input >> name >> traitNum;
        for(int j = 0; j < traitNum; j++){
            string trait;
            input >> trait;
            animals[i].insert(trait);
        }
    }
    int curr = 0, maxNum = INT32_MIN;
    for(int i = 0; i < n; i++) for(int j = i+1; j < n;j++){
        curr = numCommon(animals[i], animals[j]);
        maxNum = max(maxNum, curr);
    }
    cout << maxNum + 1 << endl;
    return 0;
}