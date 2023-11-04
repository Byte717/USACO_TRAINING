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
struct Laptop{
    int price;
    int quality;
};


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int n; cin >> n;
    vector<Laptop> laptops;
    for(int i = 0;i < n;i++){
        int a, b; cin >> a >> b;
        laptops.push_back(Laptop{a,b});
    }
    sort(all(laptops),[](const Laptop &l1, const Laptop &l2){
        return l1.price < l2.price;
    });
    bool dimaCorrect = true;
    for(int i = 1; i < n;i++){
        if(laptops[i-1].quality > laptops[i].quality){
            dimaCorrect = false;
            break;
        }
    }
    if(dimaCorrect){
        cout << "Poor Alex" << endl;
    }else{
        cout << "Happy Alex" << endl;
    }
    return 0;
}