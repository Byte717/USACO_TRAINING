#include <bits/stdc++.h>

using namespace std; 

int main(){
    freopen("photoshoot.in","r",stdin);
    int N; cin >> N;
    vector<int> sequence;
    for(int i = 0; i < N;i+=2){
        char cow1,cow2; cin >> cow1 >> cow2;
        if(cow1 == cow2){
            continue; 
        }else if(cow1 == 'G' && cow2 == 'H'){ // GH needs to be changed, so 1 in the array to indicate change
            sequence.push_back(1); 
        }else if(cow1 == 'H' && cow2 == 'G'){ // HG is good in any place, so 0 to indicate it doesn't need to be changed.
            sequence.push_back(0);
        }
    }
    int prev = -1;
    vector<int> v; 
    for(int i = 0; i < sequence.size();i++){
        if(sequence[i] != prev){
            v.push_back(sequence[i]);
            prev = sequence[i];
        }
    }

    if(v[v.size()-1] == 0){
        v.pop_back();
    }
    cout << v.size() << endl;


    return 0;
}