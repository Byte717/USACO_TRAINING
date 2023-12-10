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

vector<bool> prime((int)1e6+5,true);
void Sieve(){
    for(int x = 2; x <= 1e6+2;x++){
        if(!prime[x]) continue;
        for(int i = 2*x; i <= 1e6;i+=x){
            prime[i] = false;
        }
    }
    prime[0] = false;
    prime[1] = false;
}

int gcd(int x, int y){
    if(y == 0) return x;
    return gcd(y, x%y); 
}

int lcm(int x, int y){
    return x*y/gcd(x,y);
}

struct X{
    ll n;
    ll pow;
};

vector<X> PrimeFactors(ll n){
    vector<X> ret; 
    for(ll i = 2; i*i <= n;i++){
        ll pow = 0;
        while(n% i == 0){
            pow++;
        }
        ret.push_back({i, pow});
        n /= (i*pow);
    }
    if(n > 1){
        ret.push_back({n,1});
    }
    return ret;
}

template <unsigned int NumBits> struct uint {
    uint64_t data : NumBits;
};
template <unsigned int NumBits> struct Int {
    int64_t data : NumBits;
};
