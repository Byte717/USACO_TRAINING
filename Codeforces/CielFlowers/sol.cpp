#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
 
using namespace std;
 
int main() {
    int r,g,b;
    cin >> r >> g >> b;
    int nr,ng,nb;
    nr = r/3;
    ng = g/3;
    nb = b/3;
    r %= 3;
    b %= 3;
    g %= 3;
    int res = nr + ng + nb + min(r, min(g, b));
    if (r == 0 && nr > 0) {
        nr--;
        r += 3;
    }
    if (g == 0 && ng > 0) {
        ng--;
        g += 3;
    }
    if (b == 0 && nb > 0) {
        b += 3;
        nb--;
    }
    res = max(nr + nb + ng + min(r, min(g, b)), res);
    cout << res << endl;
}