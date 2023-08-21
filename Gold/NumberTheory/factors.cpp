#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<ll> factors[MAXM+5];

void factors(){ // n * root(n)
    for(ll i = 1; i <= MAXM;i++){
        for(ll j = i; j <= MAXM;j += i){
            factors[j].push_back(i);
        }
    }
}

vector<ll> findFactors(int n){ // root(n)
    vector<ll> ret;
    for(int i = 2; i*i <= n;i++){
        if(n % i == 0){
            ret.push_back(i);
        }
    }
    return ret;
}
