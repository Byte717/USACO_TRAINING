#include <bits/stdc++.h>

using namespace std; 

int main(){
    ifstream input("breedflip.in");
    int n; input >> n;
    string a, b;
    input >> a >> b;
    vector<int> d(n+1);
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]) d[i] = 0; 
        else d[i] = 1;
    }
    int ans = 0;
    bool range = false;  
    for(int i = 0; i < n; i++){
        if(d[i] == 1){
            if(range == false){
                range = true;
                ans++;
            }
        }else{
            range = false;
        }

    }
    cout << ans << endl;
    return 0;
}