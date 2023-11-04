#include <bits/stdc++.h>

using namespace std; 

ifstream input("tttt.in");

char board[3][3];

int main(){
    for(int i = 0; i < 3;i++){
        input >> board[i][0] >> board[i][1] >> board[i][2];
    }
    int singles = 0, doubles = 0;
    for(int i = 0; i < 3; i++){
        set<int> cows;
        for(int j = 0; j < 3; j++){
            cows.insert(board[i][j]);
        }
        if(cows.size() == 2) doubles++;
        if(cows.size() == 1) singles++;
    }
    for(int i = 0; i < 3; i++){
        set<int> cows;
        for(int j = 0; j < 3; j++){
            cows.insert(board[j][i]);
        }
        if(cows.size() == 2) doubles++;
        if(cows.size() == 1) singles++;
    }
    set<int> cows;
    cows.insert(board[1][1]);
    cows.insert(board[0][0]);
    cows.insert(board[2][2]);
    if(cows.size() == 1) singles++;
    if(cows.size() == 2) doubles++;
    cows.clear();
    cows.insert(board[1][1]);
    cows.insert(board[2][0]);
    cows.insert(board[0][2]);
    if(cows.size() == 1) singles++;
    if(cows.size() == 2) doubles++;
    cout << singles << endl;
    cout << doubles << endl;
    return 0; 
}