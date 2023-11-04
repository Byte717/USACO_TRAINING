#include <bits/stdc++.h>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("highcard.in","r",stdin);
    int n; cin >> n;
    set<int> ElsieCards; vector<int> Elsie(n);
    for(int i = 0; i < n;i++){
        cin >> Elsie[i];
        ElsieCards.insert(Elsie[i]);
    }
    vector<int> bessie;
    for(int i = 1; i < 2*n;i++){
        if(ElsieCards.count(i) == 0){
            bessie.push_back(i);
        }
    }
    sort(bessie.begin(),bessie.end());
    sort(Elsie.begin(),Elsie.end());
    int ans = 0;
    int bCard = 0, eCard = 0;
    while(bCard < n && eCard < n){
        if(bessie[bCard] > Elsie[eCard]){
            ans++; 
            bCard++;
            eCard++;
        }else{
            bCard++;
        }
    }
    cout << ans << endl;

}