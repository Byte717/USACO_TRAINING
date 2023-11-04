#include <bits/stdc++.h>

using namespace std;

const int dX[4] = {-1, 0, 1, 0};
const int dY[4] = {0, 1, 0, -1};

function<bool(int,int)> inBound = [&](int i,int j){
    return !(i < 0 || i >= n || j < 0 || j >= m);
};