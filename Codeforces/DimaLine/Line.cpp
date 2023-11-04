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

/*
What I learned Dima line:
    -draw the base case out!!!!

*/

struct connection{
    int a, b;
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("line.in","r",stdin);
    int n; cin >> n;
    vector<int> x(n);
    for(int i =0; i < n;i++){
        cin >> x[i];
    }
    vector<connection> circles;
    for(int i = 0; i < n-1;i++){
        circles.push_back(connection{x[i],x[i+1]});
        if(circles[i].a > circles[i].b) swap(circles[i].a, circles[i].b);
    }
    for(int i = 0;i < circles.size();i++){
        for(int j = 0; j < circles.size();j++){
            if(j != i){
                 int x1 = circles[i].a, x2 = circles[i].b;
                int x3 = circles[j].a, x4 = circles[j].b;
                if(x1 < x3 && x3 < x2 && x2 < x4){
                    cout << "yes" << endl;
                    return 0;
                }else if(x3 < x1 && x1 < x4 && x4 < x2){
                    cout << "yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "no" << endl;
    return 0;
}