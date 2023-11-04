/*
ID: dhairya6
PROG: combo
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int master[3], john[3];

int dist(int i,int j){
    return min(abs(i-j), abs(n-abs(i-j)));
}

bool distFromMaster(int i, int j,int k){
    int mxDist = max(dist(i,master[0]), max(dist(j,master[1]), dist(k,master[2])));
    return mxDist <= 2;
}


bool distFromJohn(int i, int j,int k){
    int mxDist = max(dist(i,john[0]), max(dist(j,john[1]), dist(k,john[2])));
    return mxDist <= 2;
}

bool works(int i,int j,int k){
    return distFromJohn(i,j,k) || distFromMaster(i,j,k);
}

int main(){
    ifstream cin("combo.in");
    ofstream cout("combo.out");
    cin >> n;
    for(int i = 0; i < 3; i++){
        cin >> john[i];
    }
    for(int i = 0; i < 3;i++){
        cin >> master[i];
    }
    int ans = 0;
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= n;j++){
            for(int k = 1; k <= n;k++){
                if(works(i,j,k)){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}