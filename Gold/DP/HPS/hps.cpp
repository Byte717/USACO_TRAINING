#include <bits/stdc++.h>
#define ll long long

using namespace std; 


int dp[1e5][21][3];
int move[1e5];
int n,k;



int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("hps.in","r",stdin);
    cin >> n >> k;
    for(int i = 0; i < n;i++){
       char a;
       cin >> a;
       if(a == 'H') move[i] = 0;
       else if(a == 'P') move[i] = 1;
       else move[i] = 2;
    }

    int ans = 0;

    for(int i = 0; i < n;i++){
        for(int j = 0; j <= k;j++){
            for(int m = 0; m < 3;m++){
                
            }
        }
    }


    return 0;
}