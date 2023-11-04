#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a,b;

bool works(ll maxOperations){
    ll currentOP = 0;
    ll tempA = a; 
    ll diff;
    while(currentOP < maxOperations){
        ll mult = tempA*2;
        ll add =  tempA+1; 
        if(tempA%2 == 0){
            ll div = tempA/2;
            diff = min({abs(b-mult), abs(b-add), abs(b-div)});
            if(b > tempA){
                tempA += diff;
            }else{
                tempA -= diff;
            }
        }else{
            diff = min(abs(b-mult), abs(b-add));
            if(b > tempA){
                tempA += diff;
            }else{
                tempA -= diff;
            }
        }
        currentOP++;
        if(tempA == b){
            break;
        }
    }
    if(currentOP <= maxOperations) return true; 
    else return false;
}



void solve(){
    cin >> a >> b;
    ll low = 0, high = 1e18, mid, ans; 
    while(low <= high){
        mid = low + (high-low)/2;
        if(works(mid)){
            ans = mid; 
            high = mid - 1; 
        }else{
            low = mid + 1;
        }
    }
    cout << ans << endl;
}

int main(){
    freopen("soul.in","r",stdin);
    int n; cin >> n;
    while(n--){
        solve();
    }
}