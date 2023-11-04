#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    string s1; cin >> s1; 
    string s2; cin >> s2;
    int pos = 0;
    for(int i = 0; i < (int)s1.size();i++){
        pos += ((s1[i] == '+') ? 1 : -1);
    }
    int totaloutComes = 0;
    int fakePos = 0;
    for(int i = 0; i < (int)s2.size();i++){
        totaloutComes += ((s2[i] == '?') 1 : 0);
        fakePos += ((s2[i] == '+') ? 1 : -1);
    }
    if(totaloutComes == 0 && fakePos == pos){
        cout << 1 << endl;
    }
    const int distance = pos - fakePos;
    if((distance + totaloutComes)%2 != 0 || moves < abs(distance)){
        cout << 0 << endl; 
        return 0;
    }else{
        int m = (totaloutComes + abs(distance))/2;
        int c = 1;
        for(int i = 0; i < m;i++){
            c *= totaloutComes - i;
        }
        for(int i = 2; i <= m;i++){
            c /= i;
        }
        cout << (double)c/(1<<totaloutComes) << endl;
    }

    return 0;
}