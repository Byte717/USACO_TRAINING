#include <bits/stdc++.h>

using namespace std; 


int policyOne(string S){
    char State = S[0];
    int Sum = 0;
    for(int i = 1; i < S.length();i++){
        if(S[i] == 'U' && State == 'U') {continue;}
        else if(S[i] == 'U' && State == 'D'){Sum++; State='U';}
        else if(S[i] == 'D' && State == 'U'){Sum+=2;}  
        else if(S[i] == 'D' && State == 'D'){Sum++; State = 'U';}
    }
    return Sum;
}

int policyTwo(string S){
    char State = S[0];
    int Sum = 0;
    for(int i = 1; i < S.length();i++){
        if(S[i] == 'U' && State == 'U') {Sum++; State='D';}
        else if(S[i] == 'U' && State == 'D'){Sum+=2;}
        else if(S[i] == 'D' && State == 'U') {Sum++; State='D';}
        else if(S[i] == 'D' && State == 'D') {continue;}
    }
    return Sum;
}

int policyThree(string S){
    char State = S[0];
    int Sum = 0;
    for(int i = 1; i < S.length();i++){
        if(S[i] == State) continue;
        else if(S[i] == 'U' && State == 'D'){
            State = 'U';
            Sum++;
        }
        else if(S[i] == 'D' && State == 'U'){
            State = 'D';
            Sum++;
        }
    }
    return Sum;

    return 0;
}


int main(){
    string s;
    cin >> s;
    cout << policyOne(s) << endl;
    cout << policyTwo(s) << endl;
    cout << policyThree(s) << endl;


}