#include <bits/stdc++.h>

using namespace std; 


string delChar(int idx1, string str, int idx2){
    string temp = "";
    for(int k = 0; k < str.length();k++){
        if(k >= idx1 && k < idx2){
            continue;
        }else{
            temp+=str[k];
        }
    }
    return temp;
}


int main(){
    ifstream input("censor.in");
    string s; 
    string censoredWord; 
    input >> s >> censoredWord;
    int idx1 = 0; 
    int idx2 = censoredWord.length();
    string newStr = "";
    string tempStr;
    while(idx2 != s.length() - 1 ){
        for(int j = idx1; j < idx2; j++){
            tempStr.push_back(s[j]);
        }
        if(tempStr == censoredWord){
            s = delChar(idx1,s,idx2);
            idx1 = 0; 
            idx2 = censoredWord.length();
        }else{
            idx1++;
            idx2++;
            tempStr = "";
        }
    }

    cout << s << endl;
    return 0; 
}