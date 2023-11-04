#include <bits/stdc++.h>
#include <fstream>

using namespace std;

struct rectangle{
    int x1,y1,x2,y2;
    int calcArea(){
        return abs((max(x1,x2)-min(x1,x2))*(max(y1,y2)-min(y1,y2)));
    }
};

int intersection(struct rectangle rect1, struct rectangle rect2){
    return abs((min(rect1.x2,rect2.x2)-max(rect1.x1, rect2.x1))*(min(rect1.y2, rect2.y2)-max(rect1.y1,rect2.y1)));
}


int main(){
    rectangle a,b,c;
    ifstream input("billboard.in");
    input >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    input >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    input >> c.x1 >> c.y1 >> c.x2 >> c.y2;
    cout << (a.calcArea()+b.calcArea() - intersection(a,c) - intersection(b,c));
    return 0;
}