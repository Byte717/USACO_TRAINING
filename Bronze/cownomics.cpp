#include <iostream>
#include <fstream> 


using namespace std;



bool isITCommon(int column, char spotty[101][101], char notSpotty[101][101], int numCows){
    for(int i = 0; i < numCows;i++){
        for(int j = 0; j < numCows; j++){
            if(spotty[j][column] == notSpotty[i][column]) return true;
        }
    }
    return false;
}



int main(){
    ifstream input("cownomics.in");
    int numCows; int sequenceLen;
    input >> numCows >> sequenceLen;
    char spotty[101][101];
    char notSpotty[101][101];
    int spotGeneLocationCount = 0;
    for(int i = 0; i < numCows;i++){
        for(int j = 0; j < sequenceLen;j++){
            input >> spotty[i][j];
        }
    }
    for(int i = 0; i < numCows;i++){
        for(int j = 0; j < sequenceLen;j++){
            input >> notSpotty[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < sequenceLen;i++){
        if(isITCommon(i,spotty,notSpotty,numCows)){
            continue;
        }else{
            ans++;
        }
    }
    cout << ans << endl;

    return 0; 
    } 