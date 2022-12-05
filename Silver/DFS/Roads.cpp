#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream input("Roads.in");
    int n, m; input >> n >> m;
    cout << (n-1) - m << endl;
    set<pair<int,int> > connections;
    for(int i = 0; i < m; i++){
        int c1, c2; input >> c1 >> c2;
        connections.insert({c1, c2});
    }
    for(int i = 1; i < n-1; i++){
        if(!(connections.count({i, i+1}))){
            cout << i << " " << i+1 << endl;
        }
    }
    return 0;
}