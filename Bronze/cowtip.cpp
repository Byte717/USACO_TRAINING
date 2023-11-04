#include <bits/stdc++.h>

using namespace std; 

int main(){
    ifstream input("cowtip.in");
    int n; input >> n; 
    vector<long long> original(n), sorted(n);
    for(int i = 0; i < n;i++){
        long long number; 
        input >> number;
        original[i] = number;
        sorted[i] = number;
    }
    sort(sorted.begin(), sorted.end());
    int differences = 0;
    for(int i = 0; i < n;i++){
        if(sorted[i] != original[i]){
            differences++;
        }
    }
    cout << differences - 1 << endl;
    
    return 0;
}