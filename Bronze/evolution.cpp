#include <bits/stdc++.h>

using namespace std; 

int N;
vector<vector<string>> cows;
vector<string> allTraits;


bool crossing(int a, int b){
    int justA = 0, justB = 0, both = 0;
    for(int i = 0; i < N; i++){
        vector<string> v  = cows[i];
        bool hasA = false, hasB = false; 
        for(int j = 0; j < v.size();j++){
            if(v[j] == allTraits[a]) hasA = true;
            if(v[j] == allTraits[b]) hasB = true;
        }
        if(hasA && hasB){
            both++;
        }else if(hasA){
            justA++;
        }else if(hasB){
            justB++;
        }
    }
    return (both > 0 && justA > 0 && justB > 0);
}


int main(){
    freopen("evolution.in","r",stdin);
    cin >> N; 
    cows = vector<vector<string>>(N+1);
    string s; 
    for(int i = 0; i < N; i++){
        int K;
        cin >> K; 
        for(int j = 0; j < K;j++){
            cin >> s; 
            cows[i].push_back(s);
            if(find(allTraits.begin(), allTraits.end(), s) == allTraits.end()){
                allTraits.push_back(s);
            }
        }
    }


    int M = (int)allTraits.size();
    bool ok = true;
    for(int a = 0; a < M;a++) for(int b = a+1;b < M;b++){
        if(crossing(a,b)){
            ok = false;
            break;
        }
    }
    cout << (ok ? "yes":"no") << endl;


    return 0;
}