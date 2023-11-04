#include <bits/stdc++.h>

using namespace std; 

string d1,d2,d3, d4;
map<char, int> diceMap;

void solve(){
    string word; cin >> word;
    bool spellAble = true; 
    map<char, int> wordMap;
    for(int i = 0; i < word.size();i++){
        if(wordMap.count(word[i]) == 0){
            wordMap.insert(make_pair(word[i], 1));
        }else{
            wordMap[word[i]]++;
        }
    }
    for(auto& const x : wordMap){
        if(wordMap[x.first] )
    }

}


int main(){
    freopen("blocks.txt","r",stdin);
    int n; cin >> n;
    cin >> d1 >> d2 >> d3 >> d4;
    for(int i = 0; i < 6;i++){
        if(map.count(d1[i]) == 0){
            map.insert(make_pair(d1[i], 1));
        }else{
            map[d1[i]]++;
        }
    }
    for(int i = 0; i < 6;i++){
        if(map.count(d2[i]) == 0){
            map.insert(make_pair(d2[i], 1));
        }else{
            map[d2[i]]++;
        }
    }
    for(int i = 0; i < 6;i++){
        if(map.count(d3[i]) == 0){
            map.insert(make_pair(d3[i], 1));
        }else{
            map[d3[i]]++;
        }
    }
    for(int i = 0; i < 6;i++){
        if(map.count(d4[i]) == 0){
            map.insert(make_pair(d4[i], 1));
        }else{
            map[d4[i]]++;
        }
    }
    for(int i = 0; i < n;i++){
        solve();

    }

    return 0;
}