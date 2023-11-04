/*
ID: dhairya6
PROG: barn1
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream cin("barn1.in");
    ofstream cout("barn1.out");
    int m, s, c; cin >> m >> s >> c;
    vector<int> occupied(c);
    for(int i = 0; i < c;i++){
        cin >> occupied[i];
    }
    sort(occupied.begin(), occupied.end());
    int ans = s;
    ans -= occupied[0]-1;// subtract how many stall in the start;
    ans -= s - occupied.back(); // equivilent to the end stall - the last stall that you currently have
    for(int i = 0; i < c-1;i++){
        occupied[i] = occupied[i+1] - occupied[i] - 1; // difference array
    }
    occupied.pop_back();// we don't care about the last element, as it will have no difference with any stall after it
    sort(occupied.rbegin(), occupied.rend());  
    for(int i = 0; i < min(c-1,m-1);i++){ // take the first m-1 differences, or the first c-1 differences
        ans -= occupied[i]; 
    }
    cout << ans << endl;
    return 0;
}