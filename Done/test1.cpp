#include <iostream>
#include <fstream>


using namespace std; 

int main(){
    ifstream input("file2.txt");
    int A, B; 
    string str;
    getline(input, str);
    cout << str << endl;
    getline(input, str);
    cout << str << endl;
    input >> A >> B;
    cout << A << endl;
    cout << B << endl;

    return 0;
}