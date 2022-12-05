#include <bits/stdc++.h>

using namespace std; 

int main(){
    ifstream input("oddphotos.txt");
    int n; input >> n;
    int even = 0; 
    int odd = 0;
    int a;
    for(int i = 0; i < n; i++){
        input >> a; 
        if(a % 2 == 0) even++;
        else odd++;
    }
    int group = 0;
    while(odd > 0){
        if(group % 2 == 0){
            if(even == 0){
                odd-=2;
            }else{
                even--;
            }
        }
        else{
            if(odd == 0){
                break;
            }
            else{
                odd--;
            }
        }
        group++;
    }
    cout << group;
    return 0;
}