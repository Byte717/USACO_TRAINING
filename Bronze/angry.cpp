#include <bits/stdc++.h>

using namespace std;




int leftExplosison(int index,vector<unsigned long long> bales, int n){
    vector<int> exploded(n);
    fill(exploded.begin(), exploded.end(), 0);
    int r = 1; 
    int count = 0;
    bool keepGoing = true;
    while(index >= 0  && keepGoing){
        keepGoing = false;
        for(int i = index;i >= index-r;i--){
            if(bales[i] >= bales[index]-r && bales[i] < bales[index] && exploded[i] == 0){
                count++;
                exploded[i] = 1;
                keepGoing = true;
            }
        }
        index--; 
        r++;
    }
    return count;
}

int rightExplosison(int index, vector<unsigned long long> bales, int n){
    vector<int> exploded(n);
    fill(exploded.begin(), exploded.end(), 0);
    int r = 1; 
    int count = 0;
    bool keepGoing = true;
    while(index < n && keepGoing){
        keepGoing = false;
        for(int i = index;i <= index+r;i++){
            if(bales[i] <= bales[index]+r && bales[i] > bales[index] && exploded[i] == 0){
                count++;
                exploded[i] = 1;
                keepGoing = true;
            }
        }
        index++; 
        r++;
    }
    return count;
}

int main(){ 
    ifstream input("angry.in");
    int n; 
    input >> n;
    vector<unsigned long long> bales(n);
    for(int i = 0; i < n; i++){
        input >> bales[i];
    }
    sort(bales.begin(), bales.end());
    int maxExploded = INT_MIN;
    for(int i = 0; i < n; i++){
        maxExploded = max(maxExploded, rightExplosison(i,bales,n)+leftExplosison(i,bales,n)+1);
    }
    cout << maxExploded << endl;
    return 0;
}