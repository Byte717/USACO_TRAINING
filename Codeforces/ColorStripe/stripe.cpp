#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

/*
What I learned ColorStripe:
    - break into cases for certain kinds of input, like , n < 2, and n > 2;
    - think of the minimum change needed, this case, use just 3 characters;


*/

void solve2(int n, int k, string s){ // only possible are abab or baba
    int diff1 = 0, diff2 = 0;
    string s1, s2; 
    for(int i = 0; i < n;i++){
        char c1 = char('A' + i%2);
        char c2 = char('A' + (i+1)%2);
        s1 += c1;
        s2 += c2;
        if(s[i] != c1){
            diff1++;
        }
        if(s[i] != c2){
            diff2++;
        }
    }
    if(diff1 <= diff2){
        cout << diff1 << endl;
        cout << s1 << endl;
    }else{
        cout << diff2 << endl;
        cout << s2 << endl;
    }
}

void solve(int n,int k, string s){ // you only need to turn characters into a, b, or c, so just use those
    int ans = 0; 
    for(int i = 0; i < n-1;i++){
        if(s[i] == s[i-1]){
            ans++;
            if('A' != s[i-1] && 'A' != s[i+1]){
                s[i] = 'A';
            }
            if('B' != s[i-1] && 'B' != s[i+1]){
                s[i] = 'B';
            }
            if('C' != s[i-1] && 'C' != s[i+1]){
                s[i] = 'C';
            }
        }
    }
    if(n >= 2 && s[n-1] == s[n-2]){
        ans++;
        if('A' != s[n-2]){
            s[n-1] = 'A';
        }else{
            s[n-1] = 'B';
        }
    }
    cout << ans << endl;
    cout << s << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("stripe.in","r",stdin);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    if(k == 2){
        solve2(n,k,s);
    }else{
        solve(n,k,s);
    }
    return 0;
}