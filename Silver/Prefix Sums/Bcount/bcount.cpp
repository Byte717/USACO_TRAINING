#include <bits/stdc++.h>

using namespace std; 

int main(){
    ifstream input("bcount.txt");
    int N, Q; 
    input >> N >> Q;
    int cows[N+1];
    cows[0] = 0;
    pair<int,int> queries[Q];
    for(int i = 1; i <= N;i++)input >> cows[i];
    for(int i = 0; i < Q; i++) input >> queries[i].first >> queries[i].second; 
    int ones[N+1] = {};
    int twos[N+1] = {};
    int threes[N+1] = {};
    for(int i = 1; i <= N;i++){
        switch(cows[i]){
            case 1:
                ones[i] = ones[i-1] + 1;
                twos[i] = twos[i-1];
                threes[i] = threes[i-1];
                break;
            case 2:
            twos[i] = twos[i -1] + 1; 
            ones[i] = ones[i-1];
            threes[i] = threes[i-1];
            break;

            case 3:
            threes[i] = threes[i-1] + 1; 
            twos[i] = twos[i-1];
            ones[i] = ones[i-1];
        }
    }
    for(int i = 0;i < Q; i++){
        cout << (ones[queries[i].second] - ones[(queries[i].first)-1]) << " ";
        cout << (twos[queries[i].second] - twos[(queries[i].first) - 1]) << " ";
        cout << (threes[queries[i].second] - threes[(queries[i].first)-1]) << endl;
    }


    return 0; 
}