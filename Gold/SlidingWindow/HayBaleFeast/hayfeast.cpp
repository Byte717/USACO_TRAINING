#include <bits/stdc++.h>
#define ll long long
#define INF 1e5

using namespace std; 

struct haybale{
    int flavor, spice;
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("hayfeast.in","r",stdin);
    int n, m; cin >> n >> m;
    vector<haybale> meals;

    for(haybale &i : meals){
        cin >> i.flavor >> i.spice;
    }
    

    return 0;
}