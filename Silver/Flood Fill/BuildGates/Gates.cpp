#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("gates.in","r",stdin);
    int n; cin >> n;

    string s; cin >> s;

    set<pair<pair<int,int>,pair<int,int>>> visEdge;
    set<pair<int,int>> visNode;
    int ans = 0;

    pair<int,int> prev{0,0};

    visNode.insert({0,0});

    for(int i = 0; i < n;i++){
        int CurrX = prev.first, CurrY = prev.second;
        switch (s[i])
        {
        case 'N':
            CurrY++;
            break;
        case 'S':
            CurrY--;
            break;
        case 'E':
            CurrX++;
            break;
        case 'W':
            CurrX--;
            break;
        default:
            break;
        }
        if(visNode.find({CurrX,CurrY}) != visNode.end() && visEdge.find({{CurrX,CurrY},prev}) == visEdge.end()){
            ans++;
        }

        visEdge.insert({{CurrX,CurrY},prev});
        visEdge.insert({prev, {CurrX,CurrY}});
        visNode.insert({CurrX,CurrY});

        prev.first = CurrX;
        prev.second = CurrY;
    }
    cout << ans << endl
    return 0;
}