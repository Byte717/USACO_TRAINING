/*
ID: dhairya6
PROG: crypt1
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

bool isgood[10];
int n;
bool good(int i,int j){
    if(i == 0){
        return false;
    }
    while(i){
        if(!isgood[i%10]){
            return false;
        }
        i /= 10;
        j--;
    }
    if(j == 0){
        return true;
    }
    return false;
}

bool goodProd(int n,int m){
    if(!good(n,3) || !good(m,2) || !good(n*m,4)){
        return false;
    }
    while(m){
        if(!good(n*(m%10),3)){
            return false;
        }
        m/=10;
    }
    return true;
}

int main(){
    ifstream cin("crypt1.in");
    ofstream cout("crypt1.out");
    cin >> n;
    for(int i = 0; i < 10; i++){
        isgood[i] = false;
    }
    for(int i = 0; i < n;i++){
        int a; cin >> a;
        isgood[a] = true;
    }
    int ans = 0;
    for(int i = 100;i < 1000; i++){
        for(int j = 10; j < 100;j++){
            if(goodProd(i, j)){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}