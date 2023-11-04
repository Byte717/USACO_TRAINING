#include <bits/stdc++.h>
#define ll long long
using namespace std; 


int x[100000];
int c[100000];
bool isMax[100000];
int main(){
    ifstream input("reststops.in");
    ll L,N,rF,rB;
    input >> L >> N >> rF >> rB;
    for(int i = 0; i < N;i++){
        input >> x[i] >> c[i];
    }
    int mx = 0;
    for(int i = N-1; i >=0; i--){
        if(c[i] > mx){
            isMax[i] = true;
            mx = c[i];
        }
    }

    ll ans =  0, tf = 0, tb  = 0;
    int lastX  = 0;
    for(int i = 0; i < N; i++){
        if(isMax[i]){
            tf += (x[i] - lastX)*((ll)rF);
            tb += (x[i] - lastX)*((ll)rB);
            ans+=(tf-tb)*((ll)c[i]);
            lastx = x[i];
        }
    }
    cout << ans << endl;

    return 0;
}