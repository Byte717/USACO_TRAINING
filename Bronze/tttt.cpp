#include <bits/stdc++.h>

using namespace std; 

ifstream input("tttt.txt");

char board[3][3];

int singles(){
    int singlesAmt = 0;
    for(int i = 0; i < 3; i++)if((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))singlesAmt++;
    for(int i = 0; i < 3; i++)if((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))singlesAmt++;
    if((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))singlesAmt++;
    if((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))singlesAmt++;
    return singlesAmt;
}
int doubles(){
    int doublesAmt = 0; 
    for(int i = 0; i < 3;i++)if((board[i][0] == board[i][1]) || (board[i][0] == board[i][2]) || (board[i][1] == board[i][2])) doublesAmt++;
    for(int i = 0; i < 3;i++)if((board[0][i] == board[1][i]) || (board[0][i] == board[2][i]) || (board[1][i] == board[2][i])) doublesAmt++;
    if((board[0][0] == board[1][1]) || (board[1][1] == board[2][2]) || (board[0][0] == board[2][2])) doublesAmt++;
    if((board[0][2] == board[1][1]) || (board[1][1] == board[2][0]) || (board[0][2] == board[2][0])) doublesAmt++;
    return doublesAmt;
}
int main(){
    for(int i = 0; i < 3;i++){
        input >> board[i][0] >> board[i][1] >> board[i][2];
    }
    cout << singles() << endl;
    cout << doubles() << endl;
    return 0; 
}