#include <bits/stdc++.h>

using namespace std; 


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("hps.in","r",stdin);
    int n; cin >> n;
    vector<int> paper(n+1,0);
    vector<int> hoof(n+1,0);
    vector<int> scisor(n+1,0);
    for(int i = 1; i < n+1;i++){
        hoof[i] = hoof[i-1];
        paper[i] = paper[i-1];
        scisor[i] = scisor[i-1];
        char move; cin >> move;
        if(move == 'H'){
            hoof[i]++;
        }else if(move == 'S'){
            scisor[i]++;
        }else{
            paper[i]++;
        }
    }
    int maxWins = 0;
    for(int i = 0; i < n+1;i++){
        
    }

    return 0;
}