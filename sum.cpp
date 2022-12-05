#include <iostream>

using namespace std; 

string solve(int a, int b, int c){
    int sum1 = a+b;
    int sum2 = b+c;
    int sum3 = c+a;
    if(sum1 == c || sum1 == a || sum1 == b || sum2 == c || sum2 == a || sum2 == b || sum3 == c || sum3 == a || sum3 == b) return "YES";
    return "NO";
}


int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << endl;
    }
    return 0;
}