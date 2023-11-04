#include <bits/stdc++.h>

using namespace std; 

int solution(int small, int medium, int large){
    int numOfSmall = large/small;
    int numOfMedium = large/medium; 
    int currentTotal = (small*numOfSmall) + (medium*numOfMedium);
    while(currentTotal > large){
        if(currentTotal - small >= currentTotal - medium && currentTotal - small <= large){
            currentTotal = currentTotal - small;
            numOfSmall--;
        }
        else{
             currentTotal = currentTotal - medium;
             numOfMedium--;
        }
    } 
    return currentTotal;
}

int main(){
    int small, medium, large;
    ifstream input("MilkPails.txt");
    input >> small >> medium >> large; 
    cout << solution(small, medium, large);
    return 0; 
}