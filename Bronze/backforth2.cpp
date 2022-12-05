#include <bits/stdc++.h>

using namespace std;

set<vector<int> >  values;
vector<int> barn1(10), barn2(10);
void permutations(vector<int> v1, int step, vector<int> v2){
    if(step > 4){
        values.insert(v2);
        v2.pop_back();
        return;
    }
    for(int i = 0; i < v1.size();i++){
        if(step % 2 == 0){
            v2.push_back(v1[i]);
            permutations(barn1, step+1, v2);
            v2.pop_back();
        }else{
            v2.push_back(v1[i]);
            permutations(barn2, step+1, v2);
            v2.pop_back();
        }
    }
}

int main(){
    ifstream input("backForth.in");
    for(int i = 0; i < 10; i++){
        input >> barn1[i];
    }
    for(int i = 0; i < 10;i++){
        input >> barn2[i];
    }
    vector<int> v;
    permutations(barn1, 1, v);
    cout << values.size() << endl;
}