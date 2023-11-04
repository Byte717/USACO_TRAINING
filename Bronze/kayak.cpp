#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream file("kayak.in");
    int n; file >> n;
    vector<int> weights(2*n);
    for(int i = 0; i < 2* n;i++){
        file >> weights[i];
    }
    sort(weights.begin(), weights.end());
    int minStability = INT32_MAX;
    for(int i = 0; i < 2*n;i++) for(int j = i+1; j < 2* n; j++){
        vector<int> imbalance;
        for(int k = j+1; k < weights.size(); k++){
            if(k != i && k !=j)imbalance.push_back(weights[k]);
        }
        int currStability = 0;
        for(int k = 0; k < imbalance.size(); k+=2){
            currStability += abs(imbalance[k] - imbalance[k+1]);
        }
        minStability = min(minStability, currStability);
    }
    cout << minStability << endl;

    return 0;
}