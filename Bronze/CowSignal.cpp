#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream input("Cowsignal.txt");
    int M, N, K;
    string x; 
    input >> M >> N >> K;
    string Newstr;
    getline(input, x);
    for(int i = 0; i < M; i++){
        getline(input, x);
        for(int j = 0; j < N; j++){
            for(int k = 0; k < K; k++){
                Newstr += x[j];
            }
        }
        for(int y = 0; y < K;y++){
            cout << Newstr << "\n";
        }
        Newstr = "";
        
    }
    return 0;
}

