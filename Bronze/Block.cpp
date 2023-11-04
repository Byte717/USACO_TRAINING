#include <iostream>
#include <fstream> 
#include <string>
#include <utility> 


using namespace std;

int letters[26] = {};




int main(){
    ifstream input("Block.txt"); 
    int n = 0;
    string x, y;
    input >> n; 
    int count1[26] = {};
    int count2[26] = {};
    for(int i = 0; i < n; i++){
        input >> x >> y;
        for(string::iterator j = x.begin(); j != x.end();j++){
            count1[int(*j)-97]++;
        }
        for(string::iterator j = y.begin(); j != y.end();j++){
            count2[int(*j)-97]++;
        }
        for(int z = 0; z < 26;z++){
            letters[z] += max(count1[z], count2[z]);
            count1[z] = 0; 
            count2[z] = 0;
        }
    }
    for(int i = 0; i < 26;i++){
        cout << letters[i] << endl;
    }
    

    return 0;
}