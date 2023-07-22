/*
ID: dhairya6
PROG: ride
LANG: C++

*/

#include <iostream> 
#include <fstream> 
using namespace std;



string ride(string A, string B){
    long long int val1 = 1; 
    long long int val2 = 1;
    for(char i : A){
        val1 = val1 * (int(i)-64);
    }
    for(char i : B){
        val2 = val2 * (int(i)-64);
    }
    if(val1 % 47 == val2 % 47){
        return "GO";
    }else {
        return "STAY";
    }


}


int main(){
    ifstream input("ride.in");
    ofstream output("ride.out");
    string str1, str2;
    input >> str1 >> str2; 
    output << ride(str1,str2) << "\n";
    return 0;
}