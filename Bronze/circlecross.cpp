#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream input("circlecross.in");
    string s;input >> s;
    int start[26], end[26];
    fill(start,start+26, -1);
    fill(end,end+26, -1);
    for(int i = 0;i < s.size();i++){
        int curr = s[i]-'A';
        if(start[curr] == -1) start[curr] = i;
        else end[curr] = i;
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

