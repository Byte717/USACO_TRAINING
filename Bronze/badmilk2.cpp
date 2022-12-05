#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream input("badmilk.in");
    int FriendNum, MilkTypesNum, Drink, Sick;
    input >> FriendNum >> MilkTypesNum >> Drink >> Sick;
    vector<set<int>> drinks(MilkTypesNum+1);
    vector<vector<int>> allDrinks;
    vector<pair<int,int>> sickPPL;
    for(int i = 0; i < Drink;i++){
        int p, m , t;
        input >> p >> m >> t; 
        vector<int> v1 = {p,m,t};
        allDrinks.push_back(v1);
    }
    for(int i = 0; i < Sick; i++){
        int t, p;
        input >> p >> t; 
        sickPPL.push_back({p,t});
    }
    for(int i = 0; i < allDrinks.size();i++){
        for(int j = 0; j < Sick;j++){
            if(sickPPL[j].second >= allDrinks[i][2]){
                drinks[allDrinks[i][1]].insert(allDrinks[i][0]);
            }
        }
    }

    return 0;
}