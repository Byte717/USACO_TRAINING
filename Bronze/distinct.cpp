#include <bits/stdc++.h>

using namespace std; 

int main(){
    int n;cin >> n;
    vector<int> v1(n);
    for(int i = 0; i < n; i++){
        cin >> v1[i];
    }
    map<int, int> map1; 
    for(int i = 0; i < n; i++){
        map1[v1[i]]+=1;
    }
    cout << map1.size() << endl;

}