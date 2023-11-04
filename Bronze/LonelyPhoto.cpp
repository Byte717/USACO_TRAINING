#include <bits/stdc++.h>

using namespace std; 

int lonely(string s, int start, int end){
    int G = 0; 
    int H = 0; 
    for(int i = start; i <= end;i++){
        if(s[i] == 'G') G++;
        else H++;
    }
    if(G == 1 || H == 1) return 1;
    return 0;

}

int main(){
    int n; cin >> n; 
    string s; cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size()-1;i++){
        for(int j = i+2; j < s.size();j++){
            ans += lonely(s,i,j);
        }
    }
    cout << ans << endl;
    return 0;
}