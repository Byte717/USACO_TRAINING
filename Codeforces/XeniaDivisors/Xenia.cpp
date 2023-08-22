#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;
/*
WHat I learned Xenia Divisors:
    - when constructing a solution, keep a track of what you have in a frequency array.

*/


const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("xenia.in","r",stdin);
    int n; cin >> n;
    vector<int> freq(8,0), a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
        freq[a[i]]++;
    }
    if(freq[5] || freq[7]){
        cout << -1 << endl;
        return 0;
    }
    if(freq[1] != n/3 || freq[2] < freq[4] || freq[1] != freq[3] + freq[2] || freq[1] != freq[4] + freq[6]){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < freq[4];i++){
        cout << "1 2 4" << endl;
    }
    for(int i = 0; i < freq[3];i++){
        cout << "1 3 6" << endl;
    }
    for(int i = 0; i < ((n/3)-freq[3]-freq[4]);i++){
        cout << "1 2 6" << endl;
    }
    return 0;
}