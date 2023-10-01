#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

vector<int> have;

void calc(string s){
    for(int i = 0; i < 10;i++){
        if(s[i] == '1'){
            have.push_back(i+1);
        }
    }

}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("weights.in","r",stdin);
    string s; cin >> s;
    int m; cin >> m;
    calc(s);
    if(have.size() == 0 && m >= 1){
        cout << "NO" << endl;
        return 0; 
    }
    bool left = true;
    int leftAmt = 0, rightAmt = 0;
    vector<int> seq;
    int last = -1;
    while(seq.size() < m){
        if(left){
            int diff = rightAmt - leftAmt;
            auto it = upper_bound(all(have),diff);
            if(*it == last){
                it++;
            }
            if(it == have.end() || (*it) + leftAmt == rightAmt){
                cout << "NO" << endl;
                return 0;
            }
            leftAmt += (*it);
            seq.push_back(*it);
            last = (*it);
        }else{
            auto it = upper_bound(all(have), leftAmt-rightAmt);
            if(*it == last){
                it++;
            }
            if(it == have.end() || (*it) + rightAmt == leftAmt){
                cout << "NO" << endl;
                return 0;
            }
            rightAmt+=(*it);
            seq.push_back(*it);
            last = (*it);
        }
        left = !left;
    }
    cout << "YES" << endl;
    for(int i = 0; i < m;i++){
        cout << seq[i] << ' ';
    }
    cout << endl;
    return 0;
}