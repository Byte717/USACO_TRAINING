#include <bits/stdc++.h>

using namespace std;


int main(){
    ifstream input("photoshoot2.in");
    int n; input >> n; 
    int A[n], B[n];
    for(int i = 0; i < n;i++){
        input >> A[i];
    }
    for(int i = 0; i < n; i++){
        input >> B[i];
    }
    int Pos_in_B[n+1];
    Pos_in_B[0] = 0;
    for(int i = 0; i < n; i++){
        Pos_in_B[B[i]] = i+1;
    }
    for(int i = 0; i < n;i++){
        A[i] = Pos_in_B[A[i]];
    }
    int ans = 0;
    int maxSoFar = 0;
    for(int i = 0; i < n;i++){
        if(A[i] > maxSoFar){
            maxSoFar = A[i];
        }else{
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}