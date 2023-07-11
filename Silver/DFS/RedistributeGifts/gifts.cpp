#include <bits/stdc++.h>
#define ll long long

using namespace std; 
int n; 
vector<vector<int>> preferences;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("gifts.in","r",stdin);
    cin >> n;
    preferences = vector<vector<int>>(n,vector<int>(n));
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            cin >> preferences[i][j];
        }
    }
    vector<bool> taken(n+1,false);
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            if(!taken[preferences[i][j]]){
                taken[preferences[i][j]] = true;
                cout << preferences[i][j] << endl;
                break;
            }
        }
    }
    return 0;
}