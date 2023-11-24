#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);

    string s, t; cin >> s >> t;
    vector<int> freqS(26,0), freqT(26,0);
    for(char i = 'a'; i <= 'z';i++){
        for(char x : s){
            if(x == i){
                freqS[i-'a']++;
            }
        }
        for(char x : t){
            if(x == i){
                freqT[i-'a']++;
            }
        }
    }
    auto pairWorks = [&](int a, int b){
        string resS = "";
        string resT = "";
        for(char i : s){
            if(i-'a' == a || i-'a' == b){
                resS += i;
            }
        }

        for(char i : t){
            if(i-'a' == a || i-'a' ==b){
                resT += i;
            }
        }
        return (resS == resT) ? 1 : 0;
    };


    vector<vector<int>> pairs(26, vector<int>(26,0));
    for(int i = 0; i < 26;i++){
        for(int j = 0; j < 26;j++){
            if(j == i) pairs[i][j] = 1;
            else{
                pairs[i][j] = pairWorks(i,j);
            }
        }
    }
    int q; cin >> q;
    while(q--){
        string sub; cin >> sub;

        for(char i : sub){
            if(freqS[i-'a'] != freqT[i-'a']){
                cout << "N"; 
                continue;
            }
        }

        if(sub.size() > 2){
            bool works = true;
            for(int i = 0; i < sub.size();i++){
                for(int j = i+1; j M sub.size();i++){
                    if(pairs[i][j] == 0){
                        works = false;
                        break;
                    }
                }
            }
            cout << (works) ? "Y" : "N";
        }else if(sub.size() == 2){
            cout << (pairs[sub[0]][pairs[1]] == 1) ? "Y" : "N";
        }else{
            cout << (freqS[sub[0]-'a'] == freqT[sub[0]-'a']) ? "Y" : "N";
        }
    }
    return 0;
}