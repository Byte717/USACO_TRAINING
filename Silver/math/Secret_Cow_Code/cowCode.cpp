#include <iostream>
#include <cstdio>
#include <string>

typedef long long ll;

using namespace std;


/*
 * solution: greedily compute the smallest k that contains the answer. 
 *
 */


char solve(string s, ll idx);


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("cowcode.in","r",stdin);
    string s;
    ll n;
    cin >> s >> n;
    cout << solve(s,n-1) << endl;

}

char solve(string s, ll idx){
    if(idx < s.size()){
        return s[idx];
    }
    ll len = s.size();
    while(2*len <= idx){
        len *= 2;
    }
    if(len == idx){
        return solve(s, len-1);
    }
    return solve(s, idx - len - 1);
}

