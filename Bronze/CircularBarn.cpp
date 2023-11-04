#include <bits/stdc++.h>

using namespace std;

vector<int> distances(1000);


void findDistance(int n, int r[], int startidx){
    int doors = 0; 
    int currentidx = startidx;
    int elementsDone = 0;
    while(elementsDone < n){
        distances[startidx] += r[currentidx]*doors;
        elementsDone++; 
        doors++;
        if(currentidx == n-1){
            currentidx = 0;
        }else{
            currentidx++;
        }

    }

}

int main(){
    ifstream input("CircularBarn.txt");
    int n; 
    input >> n;
    int r[n];
    for(int i = 0; i < n;i++) input >> r[i];
    for(int i = 0; i < n; i++){
        findDistance(n,r,i);
    }
    int min = INT16_MAX;
    for(int i = 0; i < n; i++){
        if(distances[i] < min){
            min = distances[i];
        }
    }
    cout << min << endl;

    return 0; 
}