#include <bits/stdc++.h>

using namespace std;


string s, t;
string query; 
map<char, set<pair<int,char>>> CharsInS;
map<char, set<pair<int,char>>> CharsInT;
set<pair<int, char>> SRestricted, TRestricted;

void computeMap(){
    for(char x = 'a'; x <= 'r';x++){
        for(int i = 0; i < s.length();i++){
            if(s[i] == x){
                CharsInS[x].insert({i,x});
            }
        }
        for(int i = 0; i < t.length();i++){
            if(t[i] == x){
                CharsInT[x].insert({i,x});
            }
        }
    } 
}

string FormStringForS(){
    string ret = "";
    for(auto i : SRestricted){
        ret+=i.second;
    }
    return ret;
}

string FormStringForT(){
    string ret = "";
    for(auto i : TRestricted){
        ret+=i.second;
    }
    return ret;
}

void processQuery(){
    SRestricted.clear();
    TRestricted.clear();
    for(int i = 0; i < query.length();i++){
        if(CharsInS.count(query[i]) != 0){
            for(auto i : CharsInS[query[i]]){
                SRestricted.insert(i);
            }
        }
        if(CharsInT.count(query[i]) != 0){
            for(auto i : CharsInT[query[i]]){
                TRestricted.insert(i);
            }
        }
    }
}


void solve(){
    cin >> query;
    processQuery();
    string tempS = FormStringForS();
    string tempT = FormStringForT();
    if(tempS == tempT){
        cout << "Y";
    }else{
        cout << "N";
    }
}

int main(){
    // freopen("sub.in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> t;
    computeMap();
    int q; cin >> q;
    while(q--){
        solve();
    }
    cout << endl;
    return 0;
}