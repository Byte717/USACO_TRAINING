#include <iostream> 
#include <fstream>
#include <vector> 

using namespace std;

void makeRandom(){
    ofstream diamond("diamonds.txt");
    diamond << 1000 << " " << rand();
    for(int i = 0; i < 1000;i++){
        diamond << rand() << endl;
    }
    diamond.close();
}

int main(){
    makeRandom();
    ifstream input("diamonds.txt");
    int N, K;
    input >> N >> K; 
    int diamonds[N];
    int results[N]{};
    for(int i = 0; i < N; i++){
        input >> diamonds[i]; 
    }
    for(int i = 0;i < N - 1; i++){
        for(int j = 0; j < N;j++){
            if(abs(diamonds[i] - diamonds[j]) <= K && i != j)results[i]++;
        }
    }
    int max = 0;
    for(int i = 0; i < N; i++)if(results[i] > max) max = results[i];

    cout << max << endl;

    return 0;
}