#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<ll> factors[MAXM+5];

void init(){
    for(ll i = 1; i <= MAXM;i++){
        for(ll j = i; j <= MAXM;j += i){
            factors[j].push_back(i);
        }
    }
}
