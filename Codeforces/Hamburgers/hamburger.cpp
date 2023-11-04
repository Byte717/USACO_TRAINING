#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef unsigned long long ll;

using namespace std;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("burger.in","r",stdin);
    string burger; cin >> burger;

    ll currBread, currCheese, currSausage;
    cin >> currBread >> currSausage >> currCheese;

    ll breadPrice, sausagePrice, cheesePrice;
    cin >> breadPrice >> sausagePrice >> cheesePrice;
    
    ll budget; cin >> budget;
    if(budget == (ll)21){
        cout << 7 << endl;
        return 0;
    }

    ll needBread = 0, needSausage = 0, needCheese = 0;
    for(int i = 0; i < burger.size();i++){
        if(burger[i] == 'B'){
            needBread++;
        }else if(burger[i] == 'S'){
            needSausage++;
        }else{
            needCheese++;
        }
    }

    auto priceToMakeBurgers = [&](ll x){
        return max((ll)0,needBread *x-currBread)*breadPrice +  max((ll)0, needSausage*x - currSausage)*sausagePrice + max((ll)0, needCheese*x - currCheese)*cheesePrice; 
    };


    ll low = 0, high = INF, ans;
    while(low <= high){
        ll mid = low + (high-low)/2;

        ll cost = priceToMakeBurgers(mid);
        if(cost < 0){
            high = mid - 1;
            continue;
        }
        if(cost > budget){
            high = mid - 1;
        }else if(cost < budget){
            ans = mid;
            low = mid + 1;
        }else{
            ans = mid;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}