#include <bits/stdc++.h>

using namespace std; 

int main(){
    ifstream input("cownomics.in");
    int n, m; input >> n >> m;
    string spotty[n];
    string notSpotty[n];
    for(int i = 0; i < n;i++)input >> spotty[i];
    for(int i = 0; i < n;i++)input >> notSpotty[i];
    int numTimes = 0; 
    bool explains = true; 
    for(int i = 0; i < m - 2; i++) for(int j = i+1; j < m - 1; j++) for(int k = j+1; k < m;k++){
        set<string> genes;
        for(auto const& c : spotty){
            genes.insert(string(3,c[i]+c[j]+c[k]));
        }
        for(auto const& c : notSpotty){
            if(genes.count(string(3,c[i]+c[j]+c[k]))){
                explains = false;
            }
        }
        if(explains) numTimes++;
        explains = true;
    } 
    cout << numTimes;
    return 0;
}