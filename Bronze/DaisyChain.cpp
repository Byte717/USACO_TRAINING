#include <bits/stdc++.h>

using namespace std;

bool isAverage(vector<int> arr, int i, int j){
    int sum = 0;
    for(int x = i; x <= j;x++){
        sum+=arr[x];
    } 
    float avg = (float)sum/(j-i+1);
    int NotAvg = sum/(j-i+1);
    if(!(avg - NotAvg > 0)){
        for(int x = i; x <= j;x++){
            if(arr[x] ==  avg){
                return true;
        }
    }
    return false;
    }
    return false;
}


int main(){
    ifstream input("DaisyChain.txt");
    int N;
    input >> N;
    vector<int> flowers(N+1);
    flowers[0] = 0;
    int x;
    int numOfAverages = 0;
    for(int i = 1; i <= N; i++){
        input >> flowers[i];
    }
    for(int i = 1;i <= N-1; i++){
        for(int j = i+1; j <= N;j++){
            if(isAverage(flowers,i,j)){
                numOfAverages++;
            }
        }
    }
    cout << numOfAverages+N << endl;


    return 0;
}