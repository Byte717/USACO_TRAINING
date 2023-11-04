#include <bits/stdc++.h>

using namespace std;



int main(){
    ifstream input("mowing.txt");
    int N, Steps;
    char Direction; 
    vector<pair<int,int>> coordinates;
    int x = 0;
    int y = 0;
    input >> N; 
    for(int i = 0; i < N;i++){
        input >> Direction >> Steps;
        for(int j = 0; j < Steps; j++){
            coordinates.push_back(std::make_pair(x,y));
            if(Direction == 'N')y++;
            if(Direction == 'S')y--;
            if(Direction == 'E')x++;
            if(Direction == 'W')x--;
        }
    }
    int min = INT16_MAX;
    for(int i = 0;i < coordinates.size()-1;i++){
        for(int j = 1; j < coordinates.size();j++){
            if((coordinates[i].first == coordinates[j].first && coordinates[i].second == coordinates[j].second) && min > i - j && i != j){
                min = abs((i)-(j));
            }
        }
    }
    cout << min << endl;

    return 0;
}