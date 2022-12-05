#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream input("badmilk.in");
    int FriendNum, MilkTypesNum, Drink, Sick;
    input >> FriendNum >> MilkTypesNum >> Drink >> Sick;
    vector<set<int>> drinks(MilkTypesNum+1);
    pair<int,int> drinkAll[MilkTypesNum+1];
    vector<pair<int,int>> sickPPL(Sick);
    for(int i = 0; i < Drink; i++){
        int p, m, t; 
        input >> p >> m >> t;
        drinkAll[m].insert(make_pair(p, t));
    }
    for(int i = 0; i < Sick; i++){
        int t, p;
        input >> p >> t; 
        sickPPL.push_back(make_pair(p,t));
    }
    for(int i = 1; i <= MilkTypesNum;i++){
        for(int j = 0; j < drinkAll[i].size();j++){
            for(int k = 0; k < sickPPL;k++){
                if(sickPPL[k].first == drinkAll[i][j].first && sickPPL[k].second < drinkAll[i][j].second){
                }
            }
        }
    }
    int maxCount = 0; 
    int currCount = 0;
    bool allSicK = true;
    for(int i = 1; i <= MilkTypesNum;i++){
        for(int j = 0; j < Sick; j++){
            if(drinks[i].count(sickPPL[j]) == 0) allSicK = false;
        }
        if(allSicK) currCount += drinks[i].size();
        maxCount = max(maxCount, currCount);
        currCount = 0;
    }
    cout << maxCount << endl;
    return 0;
}