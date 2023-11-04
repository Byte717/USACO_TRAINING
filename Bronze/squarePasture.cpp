#include <bits/stdc++.h>

using namespace std; 


struct rect{
    int x1,y1,x2,y2;
};

int findSquare(struct rect rect1, struct rect rect2){
    int dimension1 = max(rect1.x2,rect2.x2) - min(rect1.x1,rect2.x1);
    int dimension2 = max(rect1.y2, rect2.y2) - min(rect1.y1,rect2.y1);
    return max(dimension1,dimension2)*max(dimension1,dimension2);
}

int main(){
    ifstream input("square.in");
    rect a, b;
    input >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    input >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    cout << findSquare(a,b);


    return 0; 
}