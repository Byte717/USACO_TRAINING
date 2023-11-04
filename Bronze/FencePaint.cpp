#include <iostream>
#include <fstream>
#include <vector> 

using namespace std;


int main(){
    ifstream input("paint.txt");
    int a, b, c, d;
    input >> a >> b >> c >> d;
    int total = (b-a) + (c-d);
    int overlap = max(a,c) - min(b,d);
    cout << total - overlap;
    
}

