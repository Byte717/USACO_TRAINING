#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

/*
What I learned Moobuzz: Revisit
    - sequences tips:
        -either find repitition or reconstruct based on condition
*/

bool ok(int x){return x%3 && x%5;}
vector<int> store;
int calc(int n){
    int num = (n-1)/8;
    return store[n-8*num-1]+15*num;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    for(int i = 1; i < 16;i++){
        if(ok(i)){
            store.push_back(i);
        }
    }
    return 0;
}