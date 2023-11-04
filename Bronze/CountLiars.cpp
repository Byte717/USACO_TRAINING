#include <bits/stdc++.h>

using namespace std; 


int main(){
    ifstream input("CountLiars.txt");
    int n; input >> n;
    int num;char direction;
    vector<pair<int, char>> loc;
    for(int i = 0; i < n; i++){
        input >> direction >> num;
        loc.push_back(std::make_pair(num,direction));
    }
    sort(begin(loc), end(loc));

    int minLiars = n;
    for(int i = 0; i < n; i++){
        int currLiars = 0;
        for(int j = 0; j < i; j++){
            if(loc[j].second == 'L') currLiars++;
        }
        for(int j = i+1; j < n; j++){
            if(loc[j].second == 'G') currLiars++;
        }
        minLiars = min(currLiars,minLiars);
    }
    cout << minLiars;
    return 0; 
}