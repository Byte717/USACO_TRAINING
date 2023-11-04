#include <bits/stdc++.h>

using namespace std; 

bool sameDirections(vector<pair<int,int>,pair<char,int>> cows){

}

int main(){
    ifstream input("Rut.txt");
    int numCows;input >> numCows; 
    vector<pair<pair<int,int>,pair<char,int>>> cows[numCows];
    vector<pair<int,int>> locations;  
    for(int i = 0; i < numCows;i++){
        input >> cows[i].second.first >> cows[i].first.first >> cows[i].first.second; 
        cows[i].second.second = 0; 
    }
    while(cows.size() == 0 || )

    return 0; 
}