#include <bits/stdc++.h>

using namespace std;

set<string> names = {"Bessie", "Buttercup", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

int main(){
    ifstream input("lineup.in");
    int n; input >> n;
    string name1, name2, gib1, gib2, gib3, gib4;
    set<set<string> > nextTo;
    for(int i = 0; i < n; i++){
        input >> name1 >> gib1 >> gib2 >> gib3 >> gib4 >> name2;
        names.erase(name1);
        names.erase(name2);
        for(set<string>::iterator j = nextTo.begin(); j != names.end();j++){
            
        }       
    }

    return 0;
}