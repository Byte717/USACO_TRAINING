
#include <bits/stdc++.h>

using namespace std;

vector<int> pointsCount;
int points = 0;

void calcPoints(int swaps,int shell, vector<vector<int>> data){
    int a, b, g;
    for(int i = 0; i < swaps; i++){
        a = data[i][0];
        b = data[i][1];
        g = data[i][2];
        if(shell == a){
            shell = b;
        }else if (shell == b){
            shell = a;
        }
        if(g == shell){
            points++;
        }
    }
    pointsCount.push_back(points);
    points = 0;
}



int main(){
    ifstream input("shell.in");
    int swaps = 0;
    vector<vector<int>> x;
    vector<int> temp;
    int a,b,g;
    input >> swaps;
    for(int i = 0; i < swaps; i++){
        input >> a >> b >> g;
        temp.push_back(a);
        temp.push_back(b);
        temp.push_back(g);
        x.push_back(temp);
        temp.clear();
    }
    calcPoints(swaps, 1, x);
    calcPoints(swaps, 2, x);
    calcPoints(swaps, 3, x);
    int max = 0;
    for(int i = 0; i < 3;i++){
        if(pointsCount[i] > max){
            max = pointsCount[i];
        }
       
    }
    cout << max;

   
    return 0;
}