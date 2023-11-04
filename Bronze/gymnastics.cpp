#include <bits/stdc++.h>

using namespace std; 

int main(){
    ifstream input("gymnastics.in");
    freopen("gymnastics.out","w",stdout);
    int k, n;
    input >> k >> n; 
    int rankings[n]{};
    map<pair<int,int>, int> Counts;
    for(int i = 0;i < n;i++){
        input >> rankings[i];
    }
    for(int i = 0;i < n-1;i++){
        for(int j = i+1;j < n;j++){
            pair<int,int> p1;
            p1.first = rankings[i];
            p1.second = rankings[j];
            Counts.insert({p1,1});
        }
    }
    for(int i = 1; i < k; i++){
        for(int j = 0;j < n;j++){
            input >> rankings[j];
        }
        for(int j = 0; j < n - 1; j++){
            for(int k = j+1; k < n;k++){
                pair<int ,int> key;
                key.first = rankings[j];
                key.second = rankings[k];
                if(Counts.count(key) == 0){
                    continue;
                }else{
                    Counts[key] += 1;
                }
            }
        }
    }
    int ans = 0; 
    for(auto const& x : Counts){
        if(x.second == k){
            ans++;
        }
    }
    cout << ans; 

    return 0; 
}
