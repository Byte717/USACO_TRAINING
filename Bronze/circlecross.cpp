#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream input("circlecross.in");
    string s;input >> s;
    int start[26], end[26];
    fill(start,start+26, -1);
    fill(end,end+26, -1);
    for(int i = 0;i < s.size();i++){
        if(start[s[i]-'A'] == -1) start[s[i]-'A'] = i;
        else end[s[i]-'A'] = i;
    }
    int ans = 0;
    for(int i = 0;i < 26;i++){
        for(int j = 0; j < 26;j++){
            if((start[i] < start[j]) && (start[j] < end[i]) && (end[i] < end[j])) ans++; 
        }
    }
    cout << ans << endl;
    return 0;
}