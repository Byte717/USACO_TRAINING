#include <bits/stdc++.h>

using namespace std;

long long * CopyArr(long long arr1[], long long arr2[], int size){
    for(int i = 0; i < size;i++){
        arr2[i] = arr1[i];
    }
    return arr2;

}

int main(){
    ifstream input("BovineShuffle.txt");
    int num_of_cows;
    input >> num_of_cows;
    int swapOrder[num_of_cows];
    long long int Cows1[num_of_cows];
    long long int Cows2[num_of_cows];
    int x;
    for(int i = 0; i < num_of_cows; i++){
        input >> x;
        swapOrder[i] = x - 1 ;
    }
    
    for(int i = 0; i < num_of_cows; i++){
        input >> x;
        Cows1[i] = x;
    }

    for(int x = 0; x < 3;x++){
        for(int i = 0; i < num_of_cows;i++){
            Cows2[i] = Cows1[swapOrder[i]];
        }
        CopyArr(Cows2,Cows1,num_of_cows);
        
    }

    for(int i = 0; i < num_of_cows; i++){
        cout << Cows1[i] << endl;
    }



    return 0;
}

