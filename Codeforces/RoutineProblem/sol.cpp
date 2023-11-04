#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

int gcd(int x, int y){
    if(y == 0) return x;
    return gcd(y, x%y); 
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a,b, x, y;
    cin >> x >> y >> a >> b;
    double t = (b*x)/(a*1.0);
    int p, q;
    if(t > y)
    {
    	p = a*y*y;
    	q = b*x*y;
    }
    else
    {
    	p = b*x*x;
    	q = a*y*x;
    }
  	int k = gcd(p,q);
    p/= k;
    q/= k;
 
    p = abs(q-p);
    cout << p << "/" << q;
    return 0;
}
    

