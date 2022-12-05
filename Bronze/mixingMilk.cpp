#include <bits/stdc++.h>

using namespace std; 




int main(){
    ifstream input("mixingMilk.txt");
    vector<int> amounts ={0,0,0}; 
    vector<int> capacities = {0,0,0};
    input >> capacities[0] >> amounts[0];
    input >> capacities[1] >> amounts[1];
    input >> capacities[2] >> amounts[2];
    int current = 0;
    int amount_Transfered;
    for(int pours = 0; pours < 100; pours++){
            amount_Transfered = min(amounts[current % 3],capacities[(current+1) % 3]-amounts[(current+1)%3]);
            amounts[(current)%3] -= amount_Transfered;
            amounts[(current+1)%3] += amount_Transfered;
            current++;
    }
   cout << amounts[0] << "\n";
   cout << amounts[1] << "\n";
   cout << amounts[2] << "\n";


    return 0; 

}