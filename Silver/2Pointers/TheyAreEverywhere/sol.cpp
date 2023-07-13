#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n; cin >> n;
    vector<char> arr(n);
    unordered_set<char> distinct;
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        distinct.insert(arr[i]);
    }
    int ans = INF;
    int left = 0;
    map<char,int> pokemons;
    for(int right = 0; right < n;right++){
        pokemons[arr[right]]++;
        while(left < right && pokemons.count(arr[left]) > 0 && pokemons[arr[left]] > 1){
            pokemons[arr[left]]--;
            left++;
        }
        if(pokemons.size() == distinct.size()){
            ans = min(ans, right-left+1);
        }
    }
    cout << ans << endl;
    return 0;
}