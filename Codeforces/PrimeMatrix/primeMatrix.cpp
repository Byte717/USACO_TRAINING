#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

vector<bool> prime((int)1e6+5,true);
void Sieve(){
    for(int x = 2; x <= 1e6+2;x++){
        if(!prime[x]) continue;
        for(int i = 2*x; i <= 1e6;i+=x){
            prime[i] = false;
        }
    }
}
vector<int> primes;
void process(){
    for(int i = 2; i <= 1e6+2;i++){
        if(prime[i]){
            primes.push_back(i);
        }
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("primeMatrix.in","r",stdin);
    Sieve();
    process();
    prime[0] = false;
    prime[1] = false;
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            cin >> grid[i][j];
        }
    }
    int mnRow = 1e6;
    for(int row = 0; row < n;row++){
        int currentCost = 0;
        for(int j = 0; j < m;j++){
            if(prime[grid[row][j]]){continue;}
            currentCost += *(lower_bound(all(primes), grid[row][j])) - grid[row][j]; 
        }
        mnRow = min(mnRow, currentCost);
    }
    int mnCol = 1e6;
    for(int column = 0; column < m;column++){
        int currentCost = 0;
        for(int j = 0; j < n;j++){
            if(prime[grid[j][column]]){continue;}
            currentCost += *(lower_bound(all(primes), grid[j][column])) - grid[j][column];
        }
        mnCol = min(mnCol, currentCost);
    }
    cout << min(mnCol, mnRow) << endl;
    return 0;
}