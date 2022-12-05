/*
ID: dhairya6
TASK: friday
LANG: C++
*/



#include <iostream>
#include <fstream> 
#include <unordered_map> 
#include <vector>

using namespace std;

unordered_map<int, int> dayMap;
vector<int> dates{3, 28, 14, 4, 9, 6, 11, 8, 5, 10, 7, 12};


bool isLeap(int year){
    if(year % 100 == 0 && year % 400 == 0){
        return true;
    }
    else if(year % 4 == 0) {
        return true;
    }else{
        return false;
    }
}

void doomsDay(int n){ 
    int anchor;
    int years_passed = 0;
    int day;
    for(int i = 1900; i < 1900+n; i++,years_passed++){
        if(isLeap(i) == true) {dates[0] = 4;dates[1] = 29;}
        anchor = (3 + years_passed + (years_passed/4)) % 7;
        for(int i = 0;i < 12; i++){
            day = (abs(13 - dates[i]) + anchor) % 7;
            dayMap[day] += 1;
        }
        dates[0] = 3;
        dates[1] = 28;
    }

}

int main(){
    ifstream input("friday.in");
    int x; 
    input >> x;
    ofstream output("friday.out");
    for(int i = 0; i < 7; i++){
        dayMap[i] = 0;
    }
    doomsDay(x);
    output << dayMap[6] << " " << dayMap[0] << " " << dayMap[1] << " " << dayMap[2] << " " << dayMap[3] << " " << dayMap[4] << " " << dayMap[5];

    return 0;
}