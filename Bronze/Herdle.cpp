#include <bits/stdc++.h>

using namespace std; 

int main(){
    ifstream input("Herdle.txt");
    char ans[3][3];
    char guess[3][3];
    for(int i = 0;i < 3;i++){
        for(int j = 0; j < 3; j++){
            input >> ans[j][i];
        }
    }
    for(int i = 0;i < 3;i++){
        for(int j = 0; j < 3; j++){
            input >> guess[j][i];
        }
    }
    int green = 0;
    for(int i = 0;i < 3;i++){
        for(int j = 0; j < 3; j++){
            if(guess[j][i] == ans[j][i])green++;
        }
    }
    map<int, int>  letters;
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3; j++){
            if(letters.count(int(ans[j][i])) == 0){
                letters.insert(make_pair(int(ans[j][i]), 1));
            }else{
                letters[ans[j][i]] +=1;
            }
        }
    }
    int yellow = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(letters.count(int(guess[j][i])) != 0){
                yellow++;
                letters[guess[j][i]]--;
                if(letters[guess[j][i]] == 0){
                    letters.erase(int(guess[j][i]));
                }
            }
        }
    }
    yellow = yellow - green;
    cout << green << "\n" << yellow << endl;
    return 0;
}