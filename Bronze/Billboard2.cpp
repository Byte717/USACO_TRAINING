#include <bits/stdc++.h>

using namespace std; 

struct rect{
    int x1,y1,x2,y2;
    int calcArea(){
        return abs((max(x1,x2)-min(x1,x2))*(max(y1,y2)-min(y1,y2)));
    }
};

int Overlap(struct rect rect1, struct rect rect2){
    int xOverlap = max(rect1.x1,rect2.x1) - min(rect1.x2,rect2.x2);
    int yOverlap =  max(rect1.y1,rect2.y1) - min(rect1.y2,rect2.y2);
    return xOverlap*yOverlap;
}

bool cornerCovered(int x, int y, int x1, int y1, int x2, int y2){
    if(x <= x2 && x >= x1 && y >= y1 && y <= y2){
        return true;
    }else{
        return false;
    }
   
}


int main(){
    ifstream input("billboard.in");
    rect a,b;
    input >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    input >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    int corners = 0;
    if(cornerCovered(a.x1, a.y1, b.x1, b.y1, b.x2,b.y2)) corners++;
    if(cornerCovered(a.x1, a.y2, b.x1, b.y1, b.x2,b.y2)) corners++;
    if(cornerCovered(a.x2, a.y1, b.x1, b.y1, b.x2,b.y2)) corners++;
    if(cornerCovered(a.x2, a.y2, b.x1, b.y1, b.x2,b.y2)) corners++;

    if(corners < 2){
        cout << a.calcArea();
    }else if(corners == 4){
        cout << 0;
    }else{
        cout << a.calcArea() - Overlap(a, b);
    }
    return 0;
}