#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;

void solve(){
    int n, m,k; cin >> m >> n >> k;
    vector<int> emailToFolder(n);
    vector<vector<int>> folderToEmail(m), fileTiming(m);
    vector<bool> filed(n), skipped(n), inWindow(n);
    for(int i = 0; i < n;i++){
        cin >> emailToFolder[i];
        fileTiming[max(0, --emailToFolder[i]-k+1)].push_back(i);
        folderToEmail[emailToFolder[i]].push_back(i);
    }    
    int currEmail = 0;
    int lhsemail = 0;
    int rhsemail = 0;
    int numInWindow = 0;
    auto fileMail = [&](int id){
        if(inWindow[id]){
            inWindow[id] = false;
            numInWindow--;
        }
        assert(!filed[id]);
        filed[id] = true;
    };
    int bottom = 0;
    for(int i = 0; i < m;i++){
        if(i > bottom && i + k <= m) bottom++;
        for(int out : fileTiming[i]) fileMail(out);
        while(folderToEmail.size() > 0 && currEmail <= folderToEmail[i].back()){
            if(numInWindow == k){
                while(!inWindow[lhsemail]) lhsemail++;
                skipped[lhsemail] = true;
                inWindow[lhsemail] = false;
                numInWindow--;
            }
            if(emailToFolder[currEmail] >= i && emailToFolder[currEmail] <= i + k -1){
                filed[currEmail++] = true;
                continue;
            }
            inWindow[currEmail++] = true;
            numInWindow++;
        }
        while(currEmail < n && numInWindow < k){
            if(emailToFolder[currEmail] >= i && emailToFolder[currEmail] <= i + k -1){
                filed[currEmail++] = true;
                continue;
            }
            inWindow[currEmail++] = true;numInWindow++;
        }

        if(currEmail == n){
            while(numInWindow < k){
                if(rhsemail < 0) break;
                if(!skipped[rhsemail]){
                    rhsemail--;
                    continue;
                }
                if(emailToFolder[rhsemail] < bottom){
                    cout << "NO" << endl;
                    return;
                }
                if(emailToFolder[rhsemail] <= bottom + k -1){
                    filed[rhsemail--] = true;
                    continue;
                }
                inWindow[rhsemail--] = true;
                numInWindow++;
            }
        }
    }
    for(auto out : filed){
        if(!out){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("","r",stdin);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}